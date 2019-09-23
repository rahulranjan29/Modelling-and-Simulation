#include<math.h>
#include"gauss_elimination.h"
#define max 50

double calc_heat_source(double f_x,double x1,double x2);
double calc_heat_source2(double f_x,double x1,double x2);
void element_equation(double A_element[max][max],double b_element[max],double f_x,int global_index,double x1,double x2,int n_nodes);
void assemble(double A[max][max],double b[max],double A_element[max][max],double b_element[max],double f_x,double delta_x,double Var[max],int n_nodes,int flag,double t0,double tn);
//Calculate the heat source term via evaluating the integral
double calc_heat_source(double f_x,double x1,double x2)
{
double c1=(f_x)*x2;
double c2=-((f_x)*(x1+x2))/2.0;
double c=c1+c2;
return c;
}
double calc_heat_source2(double f_x,double x1,double x2)
{
double c1=-(f_x)*x1;
double c2=((f_x)*(x1+x2))/2.0;
double c=c1+c2;
return c;
}



void element_equation(double A_element[max][max],double b_element[max],double f_x,int global_index,double x1,double x2,int n_nodes)
{
// calculate element equation of the given global index
double n1=calc_heat_source(f_x,x1,x2);
	double n2=calc_heat_source2(f_x,x1,x2);
//init A ,b	
int i=0,j=0;
	for(i=0;i<n_nodes+2;i++)
	{  b_element[i]=0;
		for(j=0;j<n_nodes+2;j++)
			A_element[i][j]=0;
	}

	A_element[global_index-1][global_index-1]=1/(x2-x1);
	A_element[global_index-1][global_index]=-1/(x2-x1);
	A_element[global_index][global_index-1]=-1/(x2-x1);
	A_element[global_index][global_index]=1/(x2-x1);

        b_element[global_index-1]=n1;
	b_element[global_index]=n2;
}



//Assemble all the element equations , form stiffness matrix and b and x vector whose relationship is given by Ax=b
void assemble(double A[max][max],double b[max],double A_element[max][max],double b_element[max],double f_x,double delta_x,double Var[max],int n_nodes,int flag,double t0,double tn)
{

double t[max];
int x=0,i=0,j=0,k=1;

for(i=0;i<n_nodes+2;i++)
{b[i]=0;
for(j=0;j<n_nodes+2;j++)
A[i][j]=0;}
for(k=1;k<=4;k++)
{
 element_equation(A_element,b_element,f_x,k,x,x+delta_x,n_nodes);x=x+delta_x;	
for(i=0;i<n_nodes+2;i++)
{	
	b[i]=b[i]+b_element[i];

for(j=0;j<n_nodes+2;j++)
{
	A[i][j]=A[i][j]+A_element[i][j];
}}
}


if(flag)//if intial temp at ends are given as boundary condition.
{
	double temp1=A[0][0];
	double temp2=A[n_nodes+1][n_nodes+1];
	double temp3=A[1][0];
	double temp4=A[n_nodes][n_nodes+1];
	A[0][0]=1;
	A[1][0]=0;
	A[n_nodes+1][n_nodes+1]=-1;
	A[n_nodes][n_nodes+1]=0;
	b[0]=b[0]-fabs(t0*temp1);
	b[1]=b[1]+fabs(t0*temp3);
	b[n_nodes]=b[n_nodes]+fabs(tn*temp2);
	b[n_nodes+1]=b[n_nodes+1]-fabs(tn*temp4);

}
gauss_elimination(A,b,t,n_nodes+2);
for(i=0;i<n_nodes+2;i++)
{   
Var[i]=t[i];
}
}







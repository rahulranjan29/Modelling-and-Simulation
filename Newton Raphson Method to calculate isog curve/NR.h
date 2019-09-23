#include<math.h>
#include"gauss_elimination.h"


void nr(double s[2],double w[2],double t[2],double x[2],double T)
{
	double lambda=100,factor=10,A[max][max],dx[max],B[max],err[2]={1,1};
	
	while(err[0]>0.0001 && err[1]>0.0001)
	{
		double R=8.314, x_a=x[0],x_b=x[1];
		A[0][0] = -2*x_a*w[0] + R*T/(1-x_a);
                A[0][1] = 2*x_b*w[1] - R*T/(1-x_b);
                A[1][0] = 2*(1-x_a)*w[0] - R*T/x_a;
                A[1][1] = -2*(1-x_b)*w[1] + R*T/x_b;
                A[0][0] *= (1+lambda);
                A[1][1] *= (1+lambda);
                B[0] = - (t[0] - T)*s[0] - x_b*x_b*w[1] + x_a*x_a*w[0] - R*T*log(1-x_b) + R*T*log(1-x_a);
                B[1] = - (t[1] - T)*s[1] - (1-x_b)*(1-x_b)*w[1] + (1-x_a)*(1-x_a)*w[0] - R*T*log(x_b) + R*T*log(x_a);
		gauss_elimination(A,B,dx,2);
		x[0]+=dx[0];
		x[1]+=dx[1];
		err[0]=fabs(dx[0])/x[0];
		err[1]=fabs(dx[1])/x[1];
		lambda/=factor;
	}}

void composition(double s[2],double w[2],double t[2],double before[200][2],double after[200][2],double output[200][3],int n,int index)
{

int i=0,j=0;
double x[2],T;

//Congruent maxima


//calculate the composition for left part of maxima
for(i=0;i<index;i++)
{
	T=before[i][1];
	x[0]=before[i][0];
	x[1]=before[i][0];
	nr(s,w,t,x,T);

	output[i][0]=T;
	output[i][1]=x[0];
	output[i][2]=x[1];
     


}

//calculate the composition for right part of the maxima

for(i=index;i<n-1;i++)
{
	T=after[i-index][1];
	x[0]=after[i-index][0];
	x[1]=after[i-index][0];
	nr(s,w,t,x,T);

	output[i][0]=T;
	output[i][1]=x[0];
	output[i][2]=x[1];
}}

















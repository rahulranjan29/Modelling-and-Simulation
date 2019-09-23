#include<math.h>
 #include<stdlib.h>
#define max 50
#include "mat_operations.h"

#define TRUE 1

void linear_activation_forward(double A_next[max][max],double W[max][max],double A[max][max],int ar,int ac,int wr,int wc);
void transpose(double A[max][max],int rows,int cols);
void init(double weight[max][max],int n_x,int n_h);
void compute(double A0[max][max],double W1[max][max],double W2[max][max],double T,int n_input,int n_hidden,int n_output);
void compute_all(double t_set[max][max],double Y_true[max][max],int n_samples,int n_features,double W1[max][max],double W2[max][max]);
void  forward_pass(double W1[max][max],double W2[max][max],double A2[max][max], double input[max][max],int n_input,int n_hidden,int n_output);
// to build a neural network with l hidden neurons in the 2nd layer



void transpose(double A[max][max],int rows,int cols)
{
double trans[cols][rows];
int i,j=0;
for(i=0;i<rows;i++)
{
	for(j=0;j<cols;j++)
	{
		trans[j][i]=A[i][j];
	}
}

for(i=0;i<cols;i++)
{
for(j=0;j<rows;j++)
{
A[i][j]=trans[i][j];
}}

}



//void init(double weight[max][max],int n_x,int n_h)
//{
//n_x : size of input layer
//n_h:size of hidden layer


//int i,j,n;
//for(i=0;i<n_x;i++)
//{

//	for(j=0;j<n_h;j++)
//		n=(rand()%100+1)*0.01; 
  //      weight[i][j]=n;
//}
//}


void compute(double A0[max][max],double W1[max][max],double W2[max][max],double T,int n_input,int n_hidden,int n_output)
{
double A1[max][max],A2[max][max];
double Y[max][max];
double d_star[max][max];
double delta_W2[max][max];
double x[max][max];
double delta_W1[max][max];


transpose(W1,n_input,n_hidden);
transpose(W2,n_hidden,n_output);

//mat2d_print(W1,2,2);
//printf("\n");


linear_activation_forward(A1,W1,A0,n_hidden,n_input,n_input,1);
//mat2d_print(A0,1,2);
//printf("\n");


linear_activation_forward(A2,W2,A1,n_output,n_hidden,n_hidden,1);

double diff=(T-A2[0][0]);
double error=pow((T-A2[0][0]),2);

double d=diff*A2[0][0]*(1-A2[0][0]);


mat2d_scalar_multiplication(A1,d,Y,n_hidden,1);

//mat2d_print(Y,1,2);
//printf("\n");



mat2d_scalar_multiplication(Y,0.6,delta_W2,n_hidden,1);
//mat2d_print(delta_W2,1,2);
//printf("\n");


double e[max][max];
mat2d_scalar_multiplication(W2,d,e,n_hidden,1);
//mat2d_print(e,1,2);
//printf("\n");

//e[1][0]=0.04529;
int i=0;
for(i=0;i<n_hidden;i++)
{
	d_star[i][0]=e[i][0]*A1[i][0]*(1-A1[i][0]);
}




transpose(d_star,2,1);

//mat2d_print(d_star,2,1);
//printf("\n");




mat2d_mat2d_multiplication(A0,d_star,x,n_input,1,1,n_hidden);

//mat2d_print(A0,1,2);
//printf("\n");

//mat2d_print(d_star,2,1);
//printf("\n");

//mat2d_print(x,2,2);
//printf("\n");

mat2d_scalar_multiplication(x,0.6,delta_W1,n_input,n_hidden);

transpose(W1,n_hidden,n_input);
transpose(W2,n_output,n_hidden);

mat2d_mat2d_addition(W1,delta_W1,W1,n_input,n_hidden,n_input,n_hidden);

mat2d_mat2d_addition(W2,delta_W2,W2,n_hidden,n_output,n_hidden,n_output);

//mat2d_print(W1,2,2);
//printf("\n");


}



void linear_activation_forward(double A_next[max][max],double W[max][max],double A[max][max],int wr,int wc,int ar,int ac)
{
double Z[max][max];


//mat2d_print(A,ac,ar);
//printf("\n");


//mat2d_print(W,wc,wr);
//printf("\n");


mat2d_mat2d_multiplication(W,A,Z,wr,wc,ar,ac);

//mat2d_print(Z,1,2);
//printf("\n");



int i,j;
for(i=0;i<wr;i++)
{
	for(j=0;j<ac;j++)
	{
		A_next[i][j]=1/(1+exp(-Z[i][j]));
                
	
}
}
//mat2d_print(A_next,ac,wr);
//printf("\n");

} 



void forward_pass(double W1[max][max],double W2[max][max],double A2[max][max], double input[max][max],int n_input,int n_hidden,int n_output)
{
double A1[n_input][n_hidden];

transpose(W1,n_input,n_hidden);
transpose(W2,n_hidden,n_output);


linear_activation_forward(A1,W1,input,n_hidden,n_input,n_input,1);

linear_activation_forward(A2,W2,A1,n_output,n_hidden,n_hidden,1);




}
void compute_all(double t_set[max][max],double Y_true[max][max],int n_samples,int n_features,double W1[max][max],double W2[max][max])
{
int n_hidden=2,n_output=1,n_input=n_features;
//double W1[n_features][n_hidden],W2[n_hidden][n_output];
//init(W1,n_input,n_hidden);
//init(W2,n_hidden,n_output);
double A0[max][max];
double A_pred[max][max];
double error=0.0;
double A_temp[max][max];
int i=0,iter=0;
//mat2d_print(t_set,5,2);


while(TRUE)
{
iter=iter+1;

if(iter%10==0&&iter!=0)
{
printf("%d iterations \n",iter);
//printf("error=%lf\n",error);
}


for(i=0;i<n_samples;i++)
{
double k=Y_true[i][0];
A0[0][0]=t_set[0][i];
A0[1][0]=t_set[1][i];

//mat2d_print(A0,1,2);
compute(A0,W1,W2,k,2,2,1);
}

for(i=0;i<n_samples;i++)
{

double h=Y_true[i][0];
A_temp[0][0]=t_set[0][i];
A_temp[0][0]=t_set[1][i];
forward_pass(W1,W2,A_pred,A_temp,2,2,1);
double pred=A_pred[0][0];
error+=pow((h-pred),2);
}
error=sqrt(error)/n_samples;
if(error<=0.02800)
{break;
}
else
{
printf("error=%lf\n",error);
error=0;
}



}}

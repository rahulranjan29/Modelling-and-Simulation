#include<stdio.h>
#include "ADI.h"
#include "io.h"
#define maxNodes 20
#define maxdt 40
int main()
{
double L1,dt,lambda,dx,k;
int n1,TN;
double T[maxdt][maxNodes][maxNodes],t[5],arr[5];
double stiffness_matrix[maxNodes][maxNodes], stiffness_Inv[maxNodes][maxNodes];
//get data
getdata("ADI_input.txt",t,arr);
//calculate lambda and others
L1=arr[0];   //length
dt=arr[1];   //time interval
k=arr[2];    //diffusion coefficient
n1=(int)arr[3];  // no. of interior points along a side
TN=(int)arr[4];  // time steps
dx=L1/(n1+1);    //nodes distance
lambda=k*dt/(dx*dx);
initialize_temp(T,n1,t);
get_stiffness_matrix(stiffness_matrix,lambda,n1);
get_mat_inverse(stiffness_matrix,stiffness_Inv,n1);
solve_ADI(stiffness_Inv,T,n1,TN,lambda);
//write data
writedata("ADI_output.txt",T,n1,TN-1);
return 0;
}

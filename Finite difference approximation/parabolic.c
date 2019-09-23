//the input file should contain: length of the rod, no of internal nodes, right end temperature, internal node temperature, left end temperature, time step, no of time steps, k
#include<stdio.h>
#include <math.h>
#include "io.h"
#include "parabolic.h"
#define max 50
int main()
{
int i,XN,TN;
double L,dx,t0,tn,ti,dt,k,lambda;
double stiffness_matrix[max][max],T[max][max],data[8];
char file_input[]="parabolic_input.txt";
char file_output[]="parabolic_output.txt";
get_data(file_input,data,8);
L=data[0];
XN=(int)data[1];
t0=data[2];
ti=data[3];
tn=data[4];
dt=data[5];
TN=(int)data[6];
k=data[7];
dx=L/(XN+1);
lambda=k*dt/(dx*dx);
get_stiffness_matrix(stiffness_matrix,lambda,XN);
initialize(T,t0,ti,tn,XN, TN);
solve_parabolic(stiffness_matrix,T,lambda,XN,TN);
write_data(file_output,T,XN,dt,TN);
return 0;
}
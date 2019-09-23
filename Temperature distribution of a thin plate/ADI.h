//include header files required
#include"gauss_elimination.h"
//other definitions if any
#define maxNodes 20
#define maxdt 40
//prototype declarations
void get_mat_inverse(double stiffness_matrix[maxNodes][maxNodes],double stiffness_Inv[maxNodes][maxNodes],int n1)
{
    int i,j;
    double b[n1],x[n1];

    for(i=0;i<n1;i++)
    {
       //memset(b,0,sizeof(b));
        for(j=0;j<n1;j++)
            b[j]=0;
        b[i]=1;
        gauss_elimination(stiffness_matrix,b,
                          x,n1);
        for(j=0;j<n1;j++)
            stiffness_Inv[j][i]=x[j];
    }
}
void get_stiffness_matrix(double a[maxNodes][maxNodes],double lambda, int n)
{
int i=0,j=0;
//code goes here
//memset(a,0,sizeof(a));
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    a[i][j]=0;

a[0][0]=2*(1+lambda);
a[0][1]=-lambda;
a[n-1][n-1]=2*(1+lambda);
a[n-1][n-2]=-lambda;
for(i=1;i<n-1;i++)
{
    a[i][i]=2*(1+lambda);
    a[i][i-1]=-lambda;
    a[i][i+1]=-lambda;
}
}
void initialize_temp(double T[maxdt][maxNodes][maxNodes],int n, double t[5])
{
int i=0,j=0;
for(i=0;i<n+2;i++)
    for(j=0;j<n+2;j++)
    T[0][i][j]=t[5];

for(i=0;i<maxNodes;i++)
    for(j=1;j<n+1;j++)
    T[i][0][j]=t[0];

for(i=0;i<maxNodes;i++)
    for(j=1;j<n+1;j++)
    T[i][j][n+1]=t[1];

for(i=0;i<maxNodes;i++)
    for(j=1;j<n+1;j++)
    T[i][n+1][j]=t[2];

for(i=0;i<maxNodes;i++)
    for(j=1;j<n+1;j++)
    T[i][j][0]=t[3];
}
void initialize_T0(double T0[maxNodes][maxNodes],double T[maxdt][maxNodes][maxNodes],int n, int xn)
{ //update T0 with the nth layer of T
int i=0,j=0;
for(i=0;i<xn+2;i++)
    for(j=0;j<xn+2;j++)
    T0[i][j]=T[n][i][j];
}
void mat_multi_square_column(double a_inv[maxNodes][maxNodes],double b[maxNodes], int n)
{ //multiply a and b having length n
  int i,j;
   double a[n];
   for(i=0;i<n;i++)
        a[i]=0;
   for(i=0;i<n;i++)
       for(j=0;j<n;j++)
    a[i]+=a_inv[i][j]*b[j];
    for(i=0;i<n;i++)
        b[i]=a[i];
}
void update_T0_1(double T0[maxNodes][maxNodes],double b[maxNodes], int column,int n)
{ //update the column of T0 with b of length n in the position ‘column’
      int i;
      for(i=0;i<n;i++)
        T0[i+1][column]=b[i];
}
void update_T0_2(double T0[maxNodes][maxNodes],double b[maxNodes], int row,int n)
{ //update the row of T0 with b of length n in the position ‘row’
      int i;
      for(i=0;i<n;i++)
        T0[row][i+1]=b[i];
}
double updateT(double T[maxdt][maxNodes][maxNodes],double T0[maxNodes][maxNodes],int n,int xn)
{ //update nth layer of T with T0 matrix of length n
     int i,j;
     for(i=1;i<xn+1;i++)
        for(j=1;j<xn+1;j++)
        T[n][i][j]=T0[i][j];
}

void solve_ADI(double a_inv[maxNodes][maxNodes], double T[maxdt][maxNodes][maxNodes], int xn, int tn,double lambda)
{
int i,j,k,t;
double T0[maxNodes][maxNodes]={0};
double b[maxNodes]={0};
for(t=1;t<tn;t++)
{
//initializing middle time layer temp profile
initialize_T0(T0,T,t-1,xn);
//frame the b matrix for first direction
for(i=1;i<=xn;i++)
{
//frame b matrix
for(j=0;j<xn;j++)
b[j]=lambda*T0[j+1][i-1]+2*(1-lambda)*T0[j+1][i]+lambda*T0[j+1][i+1];
b[0]+=lambda*T0[0][i];
b[xn-1]+=lambda*T0[xn+1][i];
//Lets solve the equations
mat_multi_square_column(a_inv,b,xn);
//update b values to the T0 matrix

update_T0_1(T0,b,i,xn);
}
//frame the b matrix for second direction
for(i=1;i<=xn;i++)
{
//frame b matrix
for(j=0;j<xn;j++)
b[j]=lambda*T0[i-1][j+1]+2*(1-lambda)*T0[i][j+1]+lambda*T0[i+1][j+1];
b[0]+=lambda*T0[i][0];
b[xn-1]+=lambda*T0[i][xn+1];
//Lets solve the equations
mat_multi_square_column(a_inv,b,xn);
//update b values to the T0 matrix
update_T0_2(T0,b,i,xn);
}
updateT(T,T0,t,xn);
}
}











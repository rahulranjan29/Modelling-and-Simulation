#include <stdio.h>
#define max 50
int mat2d_mat2d_multiplication(double a[max][max],double b[max][max],double c[max][max],int aR, int aC, int bR, int bC);
int mat2d_scalar_multiplication(double a[max][max],double scalar, double b[max][max],int ac, int ar);
void mat2d_print(double a[max][max], int ac, int ar);
int mat2d_mat2d_addition(double a[max][max], double b[max][max], double c[max][max], int ac, int ar, int bc, int br);
int row_mat2d_multiplication(double a[max], double b[max][max],double c[max][max],int ac, int br, int bc);


int mat2d_mat2d_multiplication(double a[max][max],double b[max][max],double c[max][max],int aR, int aC, int bR, int bC)
 {
   
//mat2d_print(a,aC,aR);
//printf("\n");

//mat2d_print(b,bC,bR);
//printf("\n");

    int i,j,k;
    double sum;
    if(aC!=bR)
     {
      printf("matrix mutiplication is in compatible for the dimensions chosen!\n");
      return(0);
     }
    for(i=0;i<aR;i++)
     {
      for(j=0;j<bC;j++)
       {
        sum=0;
        for(k=0;k<aC;k++)
          {
          sum=sum+a[i][k]*b[k][j];
        }
c[i][j]=sum;
       }
     }
    return(1);
 }

int mat2d_scalar_multiplication(double a[max][max],double scalar, double b[max][max],int ac, int ar)
{
   int i,j;
   for(i=0;i<ac;i++)
     for(j=0;j<ar;j++)
       b[i][j]=a[i][j]*scalar;
   return(1);
}


void mat2d_print(double a[max][max], int ac, int ar)
{
 int i,j;
 for(i=0;i<ar;i++)
  {
   for(j=0;j<ac;j++)
{    
printf("%lf\t",a[i][j]);}
   printf("\n");
 }
}

int mat2d_mat2d_addition(double a[max][max], double b[max][max], double c[max][max], int ac, int ar, int bc, int br)
 {
   int i,j;
   if(ac!=bc || ar!=br)
    {
     printf("matrix addition is not possible with the given dimensions\n");
     return(0);
    }
   for(i=0;i<ac;i++)
     for(j=0;j<ar;j++)
       c[i][j]=a[i][j]+b[i][j];
  return(1);
 }

 int row_mat2d_multiplication(double a[max], double b[max][max],double c[max][max],int ac, int br, int bc)
 {
   int i,j,k,sum;
   if(ac!=br)
     {
      printf("the matrix matrix maultiplication is not possible for the given dimensions\n");
      printf("returning from the row matrix multiplication\n");
      return(0);
     }
   for(i=0;i<ac;i++)
     {
      for(j=0;j<bc;j++)
        {
         sum=0;
         for(k=0;k<br;k++)
           sum=sum+a[k]*b[k][j];
         c[i][j]=sum;
        }
     }
   return(1);
 }

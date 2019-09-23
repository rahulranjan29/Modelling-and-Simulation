#include "gauss_elimination.h"
#define max 50
void get_stiffness_matrix(double a[max][max],double lambda, int n);
void initialize(double T[max][max],double t0,double ti,double tn,int XN, int TN);
void solve_parabolic(double a[max][max],double T[max][max],double lambda,int XN,int TN);
void get_stiffness_matrix(double a[max][max],double lambda, int n)
{
        int i=0,j=0;
        // m = XN
        //Equation 3
        for(j=0; j<n; j++){
                for(i=0; i<n; i++){
                        a[j][i] = 0;
                }
                i = j;
                if(i==0){
                        a[j][i] = 1 + (2*lambda);
                        a[j][i+1] = -lambda;
                }
                else if(i== n-1){
                        a[j][i-1] = -lambda;
                        a[j][i] = 1 + (2*lambda);
                }
                else{
                        a[j][i-1] = -lambda;
                        a[j][i] = 1 + (2*lambda);
                        a[j][i+1] = - lambda;
                }

        }
}
void initialize(double T[max][max],double t0,double ti,double tn,int XN, int TN)
{
        int i=0, j=0;
        //COMPLETE
        for(i=0; i<=TN; i++){
                for(j=0; j<XN+2; j++){
                        if(i==0)
                                T[i][j] = ti;
                        else
                                T[i][j] = 0;
                        if(j==0)
                                T[i][j] = t0;
                        else if (j== XN+1)
                                T[i][j] = tn;
                }
        }

}
void solve_parabolic(double a[max][max],double T[max][max],double lambda,int XN,int TN)
{
        int i=1,j=0;
        double b[max],t[max];
        double t0=T[0][0],tn=T[0][XN+1];
        for(i=1;i<=TN;i++)
        {
                //frame the rhs matrix, “b”
                //Equation 4 and 5
                b[0] = T[i-1][1] + lambda*T[i][0];
                for(j=1; j<XN-1; j++){
                        b[j] = T[i-1][j+1];
                }
                b[XN-1] = T[i-1][XN] + lambda*T[i][XN+1];

                //solving the equations
                gauss_elimination(a,b,t,XN);
                //updating ith row of T array
                T[i][0] = t0;
                for(j=1; j<XN+1; j++){
                        T[i][j] = t[j-1];
                }
                T[i][XN+1] = tn;
        }
}
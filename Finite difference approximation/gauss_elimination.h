//input: matrix A, matrix B, marix x (solutions) and no of equations
//this program involves partial pivoting also
//
#define max 50

void forward_eliminate(double a_d[max][max], double b_d[max], int n);
void backward_substitution(double a_d[max][max],double b_d[max],double x[max], int n);
void sort(double a_d[max][max],double b_d[max],int i_1,int n);
void swap(double a_d[max][max],double b_d[max],int target,int present,int total);
void gauss_elimination(double a[max][max],double b[max],double x[max],int n);


void gauss_elimination(double a[max][max],double b[max],double x[max],int n)
{
        int i=0,j=0;
        double a_dummy[max][max],b_dummy[max];

        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                a_dummy[i][j]=a[i][j];

                b_dummy[i]=b[i];
        }
        forward_eliminate(a_dummy,b_dummy,n);
        backward_substitution(a_dummy,b_dummy,x,n);
}

void forward_eliminate(double a_d[max][max], double b_d[max], int n)
{
        int i=0,j=0,k=0;
        double factor;
        for(i=0;i<n-1;i++)
        {
                sort(a_d,b_d,i,n);
                for(j=i+1;j<n;j++)
                {
                        if(a_d[j][i]!=0)
                        {
                                factor=a_d[i][i]/a_d[j][i];
                                a_d[j][i]=0.0;
                                for(k=i+1;k<n;k++)
                                {
                                        a_d[j][k]=a_d[i][k]-a_d[j][k]*factor;
                                }
                                b_d[j]=b_d[i]-b_d[j]*factor;
                        }
                }
        }
}

void backward_substitution(double a_d[max][max],double b_d[max],double x[max], int n)
{
        int i=n-1,j=0;
        double sum=0.0;
        for(i=n-1;i>=0;i--)
        {
                sum=0.0;
                for(j=i+1;j<n;j++)
                        sum=sum+a_d[i][j]*x[j];
                x[i]=(b_d[i]-sum)/a_d[i][i];
        }
}

void sort(double a_d[max][max],double b_d[max],int i_1,int n)
{
        int i=0;
        int pivot=i_1;
        double Max=fabs(a_d[i_1][i_1]);
        for(i=i_1+1;i<n;i++)
        {
                if(fabs(a_d[i][i_1])>Max)
                {
                        Max=fabs(a_d[i][i_1]);
                        pivot=i;
                }
        }
        if(pivot!=i_1)
                swap(a_d,b_d,pivot,i_1,n);
}

void swap(double a_d[max][max],double b_d[max],int target,int present,int total)
{
        int i=0;
        double dummy;
        for(i=present;i<total;i++)
        {
                dummy=a_d[present][i];
                a_d[present][i]=a_d[target][i];
                a_d[target][i]=dummy;
        };

        dummy=b_d[present];
        b_d[present]=b_d[target];
        b_d[target]=dummy;

};
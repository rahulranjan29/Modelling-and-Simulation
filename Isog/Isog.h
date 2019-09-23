#include <math.h>
void isog(double w[2], double s[2], double t[2], double dxb, double isog_data[][2]);
void isog(double w[2], double s[2], double t[2], double dxb, double isog_data[][2])
{
        double x=dxb,t0, h, error=10, t_;
        int i=0, j=0;
        for(i=0; x<=1.0-dxb; x+=dxb, i++)
        {
            error = 10;
            t0 = t[0] + (1-x)*(t[1]-t[0]);
	    //one-dimensional newton raphson
            while(error > 1 && j<50){
                //code follows
                t_ = t0;
                h = ((1-x)*(t[0] - t0)*s[0] + x*(t[1]-t0)*s[1] + x*(1-x)*(w[1]-w[0]) )/ ( -(1-x)*s[0] - x*s[1] );
                t0 = t0 - h;
                error = fabs(t0 - t_) / t0 * 100;
                j+=1;
            }
            isog_data[i][0] = x;
            isog_data[i][1] = t0;
        }
}

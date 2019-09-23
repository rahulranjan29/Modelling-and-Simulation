void solve_laplace(double T[20][20], int n[2], double error, double lambda);
void initialize_temp(double T[20][20], int n[2], double t[5]);
void solve_laplace(double T[20][20], int n[2], double error, double lambda)
{
        printf("Solving the laplace equation\n");
        int i=0,j=0, k=0, r=0, rmax=50, flag=0;
        double error_ij,  error_arr[n[0]][n[1]];
        for(r=0; r<rmax; r++){
                printf("Iteration %d \n", (r+1));
                //first and last row as well as column have boundary condition values
                for(i=1; i<n[0]+1; i++){
                        for(j=1; j<n[1]+1; j++){
                                double T_ij_new = 0, T_ij_old = T[i][j];
                                //LEIBMANN METHOD
                                T_ij_new = ( T[i-1][j] + T[i+1][j] + T[i][j-1] + T[i][j+1] ) / 4.0;
                                //OVERRELAXATION
                                T_ij_new = T_ij_new*lambda + (1-lambda)*T_ij_old;
                                //RELATIVE ERROR PERCENTAGE
                                error_ij = fabs( (T_ij_new - T_ij_old) / T_ij_new )*100;

                                error_arr[i-1][j-1] = error_ij;
                                T[i][j] = T_ij_new;
                        }
                }

                //checking whether all the relative errors have become less than the stopping citerion
                flag = 1;
                for(i=0; i<n[0] && flag==1; i++){
                        for(j=0; j<n[1] && flag==1; j++){
                                if(error_arr[i][j] > error){
                                        flag = 0;
                                        break;
                                }
                        }
                }

                if(flag==1){
                        return;
                }
        }
}
void initialize_temp(double T[20][20], int n[2], double t[5])
{
        int i, j =0;
        // INTERIOR POINTS
        for(i=0; i<n[0]+2; i++){
                for(j=0; j<n[1]+2; j++){
                        T[i][j] = t[4];
                }
        }
        // LEFT EDGE
        for(i=0, j=0; i<n[0]+2; i++){
                T[i][j] = t[0];
        }
        // TOP EDGE
        for(i=0, j=0; j<n[1]+2; j++){
                T[i][j] = t[1];
        }
        // RIGHT EDGE
        for(i=0, j=n[1]+1; i<n[1]+2; i++){
                T[i][j] = t[2];
        }
        // BOTTOM EDGE
        for(i=n[0]+1, j=0; j<n[1]+2; j++){
                T[i][j] = t[3];
        }
}
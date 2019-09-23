void get_data(char file_name[], int n[2], double t[5], double other[2]);
void write_data(char file_name[], double T[20][20], int n[2]);
//Obtain J square. Left, Top, Right, Bottom boundary conditions and Initial temperature of interior points, Stopping Criterion and Lambda from the file file_name
void get_data(char file_name[], int n[2], double t[5], double other[2])
{       int i=0, j_square;
        FILE *fp;
        fp=fopen(file_name,"r");   //Openining the file for reading purpose

        fscanf(fp,"%d",&j_square);

        n[0] = sqrt(j_square);
        n[1] = n[0];

        for(i=0;i<5;i++)
                {
                        fscanf(fp,"%lf",&t[i]);
                }
        for(i=0;i<2;i++)
                {
                        fscanf(fp,"%lf",&other[i]);
                }
        fclose(fp);    //Closing the file opened
}

//writes NxN no of data points to the file file_name from the two dimensional temperature array data
void write_data(char file_name[], double T[20][20], int n[2])
{
        int i=0, j=0;
        FILE *fp;
        fp=fopen(file_name,"w"); //Openining the file for writing purpose
        for(i=1;i<n[0]+1;i++)
        {
                for(j=1; j<n[1]+1; j++)
                        fprintf(fp,"%lf ", T[i][j]); //Writing the data to the file
                fprintf(fp, "\n");
        }
        fclose(fp); //Closing the file opened
}
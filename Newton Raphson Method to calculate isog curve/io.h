void getdata(char filename[],double arr[20], int n)
{
    int i=0;
    FILE *fp;
    fp=fopen(filename,"r");
    for(i=0;i<n;i++)
        fscanf(fp,"%lf",&arr[i]);
    fclose(fp);

}

int getisog(char filename[], double before[][2], double after[][2], int n){
    int i, j, index=n;
    double data[100][2], Tmax, Tmin;

    FILE *fp;
    fp = fopen(filename, "r");
    for(i=0;i<n-1;i++)
    {
        fscanf(fp,"%lf\t%lf", &data[i][0], &data[i][1]);
    }

   
    //to find the congruent maxima temperature and initialize data
    Tmax = data[0][1];
    index = 0;
    for(i=0; i<n-1; i++){
       if(data[i][1] > Tmax){
              Tmax = data[i][1];
              index = i;
            }
        }
    for(i=0; i<index; i++){
        before[i][0] = data[i][0];
        before[i][1] = data[i][1];
      }
    for(i=index; i<n-1; i++){
        after[i - index][0] = data[i][0];
        after[i - index][1] = data[i][1];
        }
    
    return index;
}

void writedata(char filename[],double data[][3],int n1)
{
    int i=0;
    FILE *fp;
    fp=fopen(filename,"w");
    for(i=0;i<n1-1;i++)
    {
        fprintf(fp,"%lf  %lf  %lf", data[i][0], data[i][1], data[i][2]);
        fprintf(fp,"\n");
    }

    fclose(fp);

}

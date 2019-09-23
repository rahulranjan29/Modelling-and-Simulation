void getdata(char filename[],double t[5],double arr[5])
{
    int i=0;
    FILE *fp;
    fp=fopen(filename,"r");
    for(;i<5;i++)
        fscanf(fp,"%lf",&t[i]);
    for(i=0;i<5;i++)
        fscanf(fp,"%lf",&arr[i]);
    fclose(fp);
}

void writedata(char filename[],double T[maxdt][maxNodes][maxNodes],int n1,int t)
{
   int i=0,j;
    FILE *fp;
    fp=fopen(filename,"w");
    for(i=0;i<n1+2;i++)
        {
        for(j=0;j<n1+2;j++)
         fprintf(fp,"%lf ",T[t][i][j]);
        fprintf(fp,"\n");
        }

    fclose(fp);

}

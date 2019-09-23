void getdata(char filename[],double arr[20], int n)
{
    int i=0;
    FILE *fp;
    fp=fopen(filename,"r");
    for(i=0;i<n;i++)
        fscanf(fp,"%lf",&arr[i]);
    fclose(fp);
}

void writedata(char filename[],double data[][2],int n1)
{
    int i=0;
    FILE *fp;
    fp=fopen(filename,"w");
    for(i=0;i<n1-1;i++)
    {
        fprintf(fp,"%lf\t%lf", data[i][0], data[i][1]);
        fprintf(fp,"\n");
    }

    fclose(fp);

}
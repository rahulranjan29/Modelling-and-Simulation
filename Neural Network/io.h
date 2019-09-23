void getdata(char filename[],double arr[20], int n)
{
    int i=0;
    FILE *fp;
    fp=fopen(filename,"r");
    for(i=0;i<n;i++)
        fscanf(fp,"%lf",&arr[i]);
    fclose(fp);

}



void writedata(char filename[],double data[max][max],int n1,int n2)
{
    int i=0,j=0;
    FILE *fp;
    fp=fopen(filename,"w");
    for(i=0;i<n1;i++)
    { 
    for(j=0;j<n2;j++)
{

        fprintf(fp,"%lf\t", data[i][j]);
        
    }fprintf(fp,"\n");}

    fclose(fp);

}

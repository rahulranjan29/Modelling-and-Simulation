#include <stdio.h>
#include"functions.h"
#include"io.h"
#define max 50
#define TRUE 1
#define FALSE 0
int main(){
	double A[max][max],b[max],Var[max];double A_element[max][max], b_element[max];
        //double delta_x=2.50,f_x=10,t0=40,tn=200;
        //int n_nodes=3;
	

        double data[max];

	char input_file[] = "input.txt";
	
	char output_file[]="output.txt";

	getdata(input_file, data, 5);
        double length=data[0];
        double delta_x=data[1];
        double f_x=data[2];
        double t0=data[3];
        double tn=data[4];
        int n_nodes=(int)(length/delta_x)-1;
	assemble(A,b,A_element,b_element,f_x,delta_x,Var,n_nodes,TRUE,t0,tn);
        //element_equation(A_element,b_element,f_x,1,0,2.5,3);

     for(int i=0;i<n_nodes+2;i++)
        {      
printf("\n");
        for(int j=0;j<n_nodes+2;j++)
        {
            printf("%lf\t",A_element[i][j]);

}}

for(int i=0;i<n_nodes+2;i++)
        {      
printf("\n%lf",Var[i]);}

	writedata(output_file,Var,n_nodes+2); //write the data to the outputfile

}

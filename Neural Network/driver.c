#include <stdio.h>
#include "Neurons.h"
#include "io.h"
#define max 50
int main(){
	double A0[max][max];
        A0[0][0]=0.4;A0[1][0]=-0.7;
        A0[0][1]=0.3;A0[1][1]=-0.5;
        A0[0][2]=0.6;A0[1][2]=0.1;
        A0[0][3]=0.2;A0[1][3]=0.4;
        A0[0][4]=0.1;A0[1][4]=-0.2;
        
        double Y_true[max][max];


        Y_true[0][0]=0.1;
        Y_true[1][0]=0.05;
        Y_true[2][0]=0.3;
        Y_true[3][0]=0.25;
        Y_true[4][0]=0.12;
        
        double W1[max][max],W2[max][max];
       char output_file[]="Weight1.txt";
char output_file1[]="Weight2.txt"; 

        W1[0][0]=0.1;W1[0][1]=0.4;W1[1][0]=-0.2;W1[1][1]=0.2;
        W2[0][0]=0.2;W2[1][0]=-0.5;

	double A2[max][max];
        double input[max][max];
        input[0][0]=0.4;
        input[1][0]=-0.7;

        compute_all(A0,Y_true,5,2,W1,W2);
        //forward_pass(W1,W2,A2,input,2,2,1);
        //mat2d_print(A2,1,1);
        

	writedata(output_file,W1,2,2);
        writedata(output_file1,W2,2,1);    
 //write the data to the outputfile

}

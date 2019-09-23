#include <stdio.h>
#include "functions.h"
#define max 50
int main(){
	
        //char output_file[]="Weight1.txt";
       //char output_file1[]="Weight2.txt"; 

        double x1=3.4,x2=1200.0,x3=1.85;
        double pred;
       pred=get_all_cases(x1,x2,x3);
       printf("%lf\t",pred);
	//writedata(output_file,W1,2,2);
        //writedata(output_file1,W2,2,1);    
 //write the data to the outputfile

}

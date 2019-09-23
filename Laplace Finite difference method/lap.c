//The sequence of data in inputfile should be (wintout commas and new lines):
//interior nodes along the x-axis,along the y-axis,temperature along the left edge, top edge,
//right edge, bottom edge, interior nodes, permissible error, lambda
#include<stdio.h>
#include <math.h>
#include "io.h"
#include "lap.h"
int main() {
int i=0;
int n[2];
double T[20][20],t[5],other[2];
char file_output[]="laplace_fdm_output.txt";
char file_input[]="lap_in.txt";
get_data(file_input,n,t,other); //read the data required for input
initialize_temp(T,n,t); //initialize the array as per boundary conditions
solve_laplace(T,n,other[0],other[1]);//Solve as per the formula provided
write_data(file_output,T,n); //write the final solution to the file
return 0;
}

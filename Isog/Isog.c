#include<stdio.h>
#include"Isog.h"
#include"io.h"
#define max 100
void main()
{
double S[2],T[2],W[2],dxb;
int n;
double isog_data[max][2], data[20];
char input_file[] = "isog_input.txt";
char output_file[]="isog.txt";
//get the data
getdata(input_file, data, 7);
n = (int) data[0];
S[0] = data[1];
S[1] = data[2];
T[0] = data[3];
T[1] = data[4];
W[0] = data[5];
W[1] = data[6];
dxb = 1.0/(n+1);
isog(W,S,T,dxb,isog_data); //calculate the values of isoG for the input
writedata(output_file,isog_data,n); //write the data to the outputfile
}
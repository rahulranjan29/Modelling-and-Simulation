#include <stdio.h>
#include "io.h"
#include "NR.h"

int main(){
	double S[2],T[2],W[2],dxb;
	int n, type, index;
	double data[20], output[200][3], before[200][2],after[200][2];
	char input_file[] = "pd_input.txt";
	char isog_file[] = "isog.txt";
	char output_file[]="pd_output.txt";

	//get the data
	getdata(input_file, data, 7);
	n = (int) data[0];
	S[0] = data[1];	S[1] = data[2];
	T[0] = data[3];	T[1] = data[4];
	W[0] = data[5];	W[1] = data[6];
	index = getisog(isog_file, before, after, n);
	composition(S, W, T, before, after, output, n, index);
	writedata(output_file,output,n); //write the data to the outputfile
}

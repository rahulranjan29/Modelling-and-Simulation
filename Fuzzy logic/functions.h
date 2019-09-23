#include<math.h>
double membership_input_var(double input_x,double left,double right,double middle,char type);
double output_var(double input_x,double middle);
double output_membership(double x1,char x1_case,double x2,char x2_case,double x3 ,char x3_case);
double get_all_cases(double x1,double x2,double x3);



double membership_input_var(double input_x,double left,double right,double middle,char type)
{

double y;
switch(type)
{
case 'S': 
 if (input_x<middle)
 {
 y=(middle-input_x)/middle;	/* code */
 }
  else
  {
  	y=0;
  }
break;

case 'M':
if(input_x<middle)
{
y=input_x/middle;

}
else
{
y=1+(middle-input_x)/(right-middle);

}
break;

case 'L':
if (input_x>middle)
{
	y=1+(right-input_x)/(middle-right);
}
else
{
 y=0;

}break;
}
return y;
}


double output_var(double input_y,double middle)
{

double x1,x2;

x1=middle+(input_y-1)*4.33;
x2=middle+(1-input_y)*4.33;



/*y=1+(input_x-middle)/4.375;

}
else
{if (input_x>=middle)
{
	y=1-(input_x-middle)/4.375;
}
else
{

	y=0;
}


}*/
double diff=fabs(x2-x1);
return diff;

}


double output_membership(double x1,char x1_case,double x2,char x2_case,double x3 ,char x3_case)
{
double m_x1=membership_input_var(x1,2.0,4.0,3.0,x1_case);
double m_x2=membership_input_var(x2,1050.0,1250.0,1150.0,x2_case);
double m_x3=membership_input_var(x3,1,2,1.5,x3_case);

//printf("%lf\n",m_x1);
//printf("%lf\n",m_x2);
//printf("%lf\n",m_x3);

double output_m;
if(m_x1<m_x2&&m_x1<m_x3)
{
	output_m=m_x1;
}
else
{
if(m_x2<m_x1&&m_x2<m_x3)
{
	output_m=m_x2;

}
else
{
	if(m_x3<m_x1&&m_x3<m_x2)
{
	output_m=m_x3;
}
}
}

//printf("%lf\n",output_m);z
return output_m;
}



double get_all_cases(double x1,double x2,double x3)
{

//ch ouput_label[15]=     {'M','VS', 'L','L','L', 'SS','LL','VL','ML','LL', 'ML','S','VL','ML','L' };
              

                  //  {SS','VS','S','MS','M','ML','L','VL','LL'};

//double  output_value[9]={59.46,63.79,68.12,72.45,76.78,81.11,85.44,89.77,94.10};

double types[15][3]={{'S','S','S'},{'L','S','S'},{'M','M','S'},{'S','L','S'},{'L','L','S'},
{'M','S','M'},{'S','M','M'},{'M','M','M'},{'L','M','M'},{'M','L','M'},{'S','S','L'},
{'L','S','L'},{'M','M','L'},{'S','L','L'},{'L','L','L'}};

double output_value[15]={76.78,63.79,85.44,85.44,85.44,59.46,94.10,89.77,81.11,94.10,81.11,68.12,89.77,81.11,85.44};
double sum_a=0,sum_b=0;
int i=0;


for(i=0;i<15;i++)
{
double mu=output_membership(x1,types[i][0],x2,types[i][1],x3,types[i][2]);
printf("%lf\t", mu);
printf("%lf\t", output_value[i]);
double area;
if(i==5||i==6||i==9)
{
 area=((4.33+output_var(mu,output_value[i]))*mu)/2.0;
 area=area/2.0;
}
else
{area=((4.33+output_var(mu,output_value[i]))*mu)/2.0;
}

printf("%lf", area);
sum_a=sum_a+output_value[i]*area;
sum_b=sum_b+area;
printf("\n");
}

//printf("%lf\n", sum_a);
//printf("%lf\n", sum_b);
double y_pred;
if (sum_b<=0)
{
 return 0;
}
else
	{
	y_pred=sum_a/sum_b;
}

return y_pred;

}

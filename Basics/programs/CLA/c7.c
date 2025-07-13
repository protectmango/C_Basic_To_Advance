/*
 WAP in C using CLA to print average and sum
of 3 float number .
 i/p: ./a.out 12.56 45.7 345.23
 o/p : sum= 403.49 avg=134.496
 */


#include<stdio.h>

double my_atof(char *);

int main(int argc, char **argv)
{
	if(argc!=4)
	{
		printf("%s <value1> <value2> <value3>\n", argv[0]);
		return 1;
	}

	double num1 = my_atof(argv[1]);
	double num2 = my_atof(argv[2]);
	double num3 = my_atof(argv[3]);

	double sum, avg;

	sum = num1 + num2 + num3;

	avg = sum/(argc-1);

	printf("Sum : %f Average : %f \n", sum, avg);

}


double my_atof(char *str)
{
	int i;

	if(str[i]=='-')
	{
		i=1;
	}
	else
	{
		i=0;
	}

	int dot=0;

	float power =1;

	double fnum=0;


	for( ;str[i]; i++)
	{
		if(!dot)
		{
			if(str[i]=='.')
			{
				dot=1;
				continue;
			}
			if(str[i]>='0'&& str[i]<='9')
			{
				fnum = fnum*10 + (str[i] - '0');
			}
			else
			{
				break;
			}
		}
		else
		{
			if(str[i]>='0'&& str[i]<='9')
			{
				fnum = fnum*10 + (str[i] -'0');
				power = power*10;
			}
			else
			{
				break;
			}
		}
	}

	if(dot)
		fnum = fnum/power;

	if(str[0]== '-')
	{
		fnum = -fnum;
	}

	return fnum;
}

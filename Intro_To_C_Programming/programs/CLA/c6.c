/*
 WAP in C using CLA to write given function.
 double my_atof(const char *nptr)
 */

#include<stdio.h>

double my_atof(const char *);


int main(int argc, char **argv)
{
	if(argc!=2)
	{
		printf("Usage : %s <value>\n",argv[0]);
		return 1;
	}

	double fnum = my_atof(argv[1]);

	printf("Float Value : %f\n", fnum);
}

double my_atof(const char *str)
{
	int i;

	if(str[0] == '-')
	{
		i=1;
	}
	else
	{
		i=0;
	}


	double fnum = 0;
	int dot = 0;
	float power  =1;
	for(; str[i] ; i++)
	{
		if(!dot)
		{
			if(str[i]=='.')
			{
				dot = 1;
				continue;
			}
			if(str[i]>='0'&&str[i]<='9')
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
			if(str[i]>='0' && str[i] <= '9')
			{
				fnum = fnum*10 + (str[i] - '0');
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

	if(str[0] == '-')
		fnum = -fnum;

	return fnum;

}

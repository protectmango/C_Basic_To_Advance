/*
 2.
WAP in C using CLA to print 1st digit of num.
 i/p: ./a.out 1234
 o/p :
 */

#include<stdio.h>

int main(int argc, char **argv)
{
	if(argc!=2)
	{
		printf("Usage: %s <number>\n",argv[0]);
		return 1;
	}


	int first_digit;

	char *str = argv[1];

	if(str[0]=='-')
	{
		if(str[1]>='0'&&str[1]<='9')
		first_digit = str[1] - '0';
		else 
			return 1;
	}
	else
	{	if(str[0]>='0'&& str[0]<='9')
		first_digit = str[0] - '0';
		else 
			return 1;
	}
	printf("First Digit is : %d\n", first_digit);
}

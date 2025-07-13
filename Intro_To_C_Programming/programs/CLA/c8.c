/*
 7.
WAP in C using CLA to implement Calculator
ex1 ./a.out 44 + 200
 o/p : 244
ex2 ./a.out 44 / 0
 o/p : FPE 
 */


#include<stdio.h>
int my_atoi(char *);
int main(int argc, char **argv)
{
	if(argc!=4)
	{
		printf("Usage : %s <num1> <operator> <num2>\n", argv[0]);
		return 1;
	}

	int num1 = my_atoi(argv[1]);
	int num2 = my_atoi(argv[3]);

	char operator = argv[2][0];

	if(operator =='/'&&num2==0)
	{
		printf("Float Point Execption\n");
		return 1;
	}
	printf("%d\n", num2);
	switch(operator)
	{
		case '+' : printf("Sum : %d\n", num1 + num2);
			   break;
		case '-' : printf("Difference : %d\n", num1 - num2);
			   break;
		case '/' : printf("Divide : %d\n", num1 / num2);
			   break;
		case '%' : printf("Remainder : %d\n", num1 % num2);
			   break;
		default :  printf("Invalid Operator\n");
	}
}

int my_atoi(char *str)
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

	int num =0;

	for(;str[i];i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			num = num*10 + (str[i] - '0');
		}
		else
		{
			break;
		}
	}


	if(str[0]=='-')
	{
		num = -num;
	}

	return num;
}

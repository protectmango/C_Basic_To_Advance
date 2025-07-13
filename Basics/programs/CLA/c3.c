/*
3.
WAP in C using CLA to prime number b/w 11
to 66 .
 i/p: ./a.out 11 66
 */

#include<stdio.h>
int isPrime(int);
int my_atoi(char *);

int main(int argc, char **argv)
{
	if(argc!=3)
	{
		printf("Usage : %s <range1> <range2>\n", argv[0]);
		return 1;
	}

	int num1 = my_atoi(argv[1]);
	int num2 = my_atoi(argv[2]);
	int i;

	for(i = num1; i<= num2; i++)
	{
		if(isPrime(i))
		{
			printf("%d ", i);
		}
	}

	printf("\n");
}

int isPrime(int num)
{
	int i;

	for(i=2; i<num; i++)
	{
		if(num%i==0)
			return 0;
	}

	return 1;

}


int my_atoi(char *str)
{
	int i;
	if(str[0]=='-'||str[0]=='+')
		i=1;
	else
		i=0;

	int num =0;
	for( ; str[i]; i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		num = num*10 + (str[i] - '0');
		else
			break;
	}

	if(str[0]=='-')
		num = -num;

	return num;
}

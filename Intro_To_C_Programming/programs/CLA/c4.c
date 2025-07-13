/*
 4.
WAP in C using CLA to print strong number b/
w 1 to 199 .
 i/p: ./a.out 1 199 
 */

#include<stdio.h>

int my_atoi(char *);
int isStrong(int );

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

	for(i=num1; i<= num2; i++)
	{
		if(isStrong(i))
		{
			printf("%d ", i);
		}
	}

	printf("\n");
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

	int num=0;

	for( ; str[i]; i++)
	{
		if(str[i]>='0'&& str[i]<='9')
		{
			num = num*10 + (str[i] - '0');
		}		
		else
		{
			break;
		}
	}

	if(str[0] == '-')
	{
		num = -num;
	}

	return num;
}



int isStrong(int num)
{
	int i;

	int sum=0;

	for(i=1; i<num;i++)
	{
		if(num%i==0)
		{
			sum += i;
		}
	}

	if(sum == num)
		return 1;
	
	return 0;

}

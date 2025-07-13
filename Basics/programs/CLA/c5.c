/*
 4.
WAP in C using CLA to take array input and
print in reverse order .
i/p: ./a.out 11 22 33 44 55
 o/p : 55 44 33 22 11
 */

#include<stdio.h>
#include<stdlib.h>

int my_atoi(char *);
int main(int argc, char **argv)
{
	if(argc<3)
	{
		printf("Usage : %s <value1> <vlaue2> ...\n",argv[0]);
		return 1;
	}


	int *arr = (int *)malloc(sizeof(int)*(argc-1));

	int i;

	for(i = 0 ; i< (argc -1) ; i++)
	{
		arr[i] = my_atoi(argv[i+1]);
	}
	for(i=(argc - 2); i>=0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int my_atoi(char *str)
{
	int i;

	if(str[0]=='-')
	{
		i=1;
	}
	else
	{
		i=0;
	}

	int num=0;


	for(; str[i]; i++)
	{
		if(str[i]>='0'&&str[i]<='9')
			num = num*10 + (str[i] - '0');
		else
			break;
	}

	if(str[0] == '-')
		num = -num;

	return num;
	
}

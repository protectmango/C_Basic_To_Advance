/*
 1.
WAP in C using CLA to write given function.
 int my_atoi(const char *nptr);
 */
#include<stdio.h>

int my_atoi(const char *);

int main(int argc, char  **argv)
{
	if(argc!=2)
	{
		printf("Usage : %s <number>\n",argv[0]);
		return 1;
	}

	int num = my_atoi(argv[1]);

	printf("Your Data is : %d\n",num);
}

int my_atoi(const char *str)
{
	int i,num=0;
	if(str[0]=='-'||str[0]=='+')
	{
		i=1;
	}
	else
	{
		i=0;
	}

	for(; str[i]; i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		num = num*10 + (str[i]-'0');
		else 
			break;
	}

	if(str[0]=='-')
	{
		num = -num;
	}

	return num;

}

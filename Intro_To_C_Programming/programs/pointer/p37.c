#include<stdio.h>
int main()
{
	int i;
	double a = 5.5;
	char *ptr;
	ptr = (char *)&a;
	for(i=0;i<=7;i++)
		printf("%d\n",*ptr++);
	return 0;
}


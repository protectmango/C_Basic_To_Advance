#include<stdio.h>
void main()
{
	int i=10;
	int *p=10;
	char **q=&p;
	printf("%d\n",*q+1);
	printf("%d\n",**q);
}

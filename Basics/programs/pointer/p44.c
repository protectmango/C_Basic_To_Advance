#include<stdio.h>
int main()
{
	char a[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,*p = a;

	for(i=0;i<5;i++)
	{
		printf("%x\n", *p++);
	}
	printf( "\n");
}

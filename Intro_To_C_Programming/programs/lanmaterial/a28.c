#include<stdio.h>
int main(void)
{
	int a[2][3];
	a[1][2]=9;
	printf("%d\n",a[1,2]);//this will provide address 
	return 0;
}


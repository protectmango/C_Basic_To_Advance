#include<stdio.h>
int main()
{

	int i,j,k,l;

	char ch;

	for(i=0;i<6;i++)
	{
		for(k=0;k<i;k++)
		{
			printf(" ");
		}

		for(j=0,ch='F'-i;j<6-i;j++)
		{
			printf("%c ",ch-j);
		}
		printf("\n");
	}
}

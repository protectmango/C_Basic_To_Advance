#include<stdio.h>
int main()
{

	int i,j,k;


	for(i=0;i<4;i++)
	{
		for(k=0;k<3-i;k++)
			printf(" ");

		for(j=0;j<=2*i;j++)
		{
			printf("*");
		}

		printf("\n");
	}
}

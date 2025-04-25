#include<stdio.h>

int main()
{
	int i,j,k;


	for(i=0;i<4; i++)
	{
		for(k=0;k<3-i;k++)
			printf(" ");

		for(j=0;j<2*i+1;j++)
		{
			if(i%2==0)
			{
				printf("%c",'A' + j);
			}
			else
			{
				printf("%d",j+1);
			}
		
		}
		printf("\n");	
	
	}

}

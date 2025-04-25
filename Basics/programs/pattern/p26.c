/*
 
      1
    2 3 2
  3 4 5 4 3
4 5 6 7 6 5 4
 


 * /





#include<stdio.h>
int main()
{
	int i,j,k,l;


	for(i=1;i<=4;i++)
	{
		for(k=0;k<=3-i;k++)
			printf("  ");


		for(j=1,l=i;j<=i;j++,l++)
		{
			printf("%d ",l);

		}
		for(j=1,l=l-2;j<i;j++,l--)
		{
			printf("%d ",l);
		}

		printf("\n");
	}

}

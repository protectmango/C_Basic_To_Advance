#include<stdio.h>
int main()
{
int arr[2][3][2] = { { { 1, 1 }, { 2, 3 }, { 4, 5 } },
                         { { 6, 7 }, { 8, 9 }, { 10, 11 } } };

	int i,j,k;

	for(i=0 ; i<2 ; i++)
	{
	
		for(j=0; j<3; j++)
		{
			for(k=0; k<2 ; k++)
			{
			
				printf("arr[%d][%d][%d] : %d\n",i,j,k,arr[i][j][k]);
			}
		}
	}


}

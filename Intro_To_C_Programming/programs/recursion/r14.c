/*
WAP in C using Recursive fun to reverse bits .
i/p : n= 31
00000000 00000000 00000000 00011111
o/p: // print binary in main function
11111000 00000000 00000000 00000000


*/


#include<stdio.h>

unsigned int reversebinary(unsigned int, int, int);

int main()
{

	unsigned int num = 0x0000000F ; 


	printf("Before : ");

	
	for(int i =31; i>=0; i--)
	{
		printf("%d",num>>i&1);
		if(i%8==0)
			printf(" ");
	}

	printf("\n");


	num = reversebinary(num,0,31);	

	printf("After : ");
	
	for(int i =31; i>=0; i--)
	{
		printf("%d",num>>i&1);
		if(i%8==0)
			printf(" ");
	}

	printf("\n");



}



unsigned int reversebinary(unsigned int num, int i, int j)
{

	if(i>=j)
		return num;

	int m = num>>i&1;
	int n = num>>j&1;
	

	if(m!=n)
	{
		num = num^1<<i;
		num = num^1<<j;
		
	}
	printf("m : %d n : %d , i : %d j : %d\n", m,n,i,j); 
	return reversebinary(num,i+1, j-1); 
	

}

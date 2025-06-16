#include<stdio.h>



int isPrime(int);

int countdivisor(int,int);


int main()
{

	int num;


	printf("Enter a num : ");
	scanf("%d", &num);


	printf("%d is %sPrime\n",num, isPrime(num) ? "":"Not ");
}


int isPrime(int num)
{

	if(num<=1)
		return 0;

	return countdivisor(num,1)==2;
}


int countdivisor(int num, int i)
{

	if(i>num)
		return 0;

	return (num%i==0) + countdivisor(num,i+1);
}









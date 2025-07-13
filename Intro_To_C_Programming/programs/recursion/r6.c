#include<stdio.h>


int isPerfect(int);

int sumoffactor(int, int, int);


int main()
{
	int num;

	printf("Enter a number :");
	scanf("%d",&num);

	if(isPerfect(num))
	{
		printf("Perfect number : %d\n", num);
	}
	else
		printf("Not Perfect\n");
}



int isPerfect(int num)
{

	if(num<=1)
	return 0;

	return sumoffactor(num, 1, 0) == num;
}


int sumoffactor(int num, int i, int sum)
{

	if(i>=num)
		return sum;


	if(num%i==0)
		sum = sum +i;

	return sumoffactor(num,i+1, sum);

}

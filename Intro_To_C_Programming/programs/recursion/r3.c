


#include<stdio.h>

int product(int);

int main()
{

	int num, result;

	printf("Enter a number :");
	scanf("%d",&num);

	result  = product(num);

	printf("Result : %d\n",result);
}


int product(int num)
{

	static int p =1;

	if(num == 0)
		return 1;

	if((num%10)%3==0)
	{
		p = num%10; 
		return p*product(num/10);
	}
	else
	{
		return product(num/10);
	}
}

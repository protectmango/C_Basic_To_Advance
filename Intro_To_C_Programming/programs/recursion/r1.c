


#include<stdio.h>

int sum(int);

int main()
{

	int num, result;

	printf("Enter a number :");
	scanf("%d",&num);

	result  = sum(num);

	printf("Result : %d\n",result);
}


int sum(int num)
{
	
	if(num==0)
		return 0;

	if((num%10)%2==0)
		return num%10 + sum(num/10);
	else
		return sum(num/10);

}




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
	static int rem=0;
	if(num > 0)
	{
		rem = rem*10 + num%10;
		sum(num/10);
	}
	
		return rem;
	
	


}

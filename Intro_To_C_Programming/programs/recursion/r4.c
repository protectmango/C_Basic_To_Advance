


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
	static int  count =0;	


	if(count<3)
	{
		count++;		
		return num%10 + sum(num/10);
	}
	else
		return 0;

}

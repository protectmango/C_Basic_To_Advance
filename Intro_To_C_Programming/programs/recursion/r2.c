


#include<stdio.h>

int count(int);

int main()
{

	int num, result;

	printf("Enter a number :");
	scanf("%d",&num);

	result  = count(num);

	printf("Result : %d\n",result);
}


int count(int num)
{
	static int c =0;
	if(num==0)
		return 0;

	if((num%10)<6)
		return c++ + count(num/10);
	else
		return count(num/10);

}

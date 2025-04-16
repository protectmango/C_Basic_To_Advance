

//Sum of last 3 Digits

#include<stdio.h>
int main()
{
	int num,sum=0,r;

	printf("Enter a num : ");
	scanf("%d",&num);

	num=num%1000; // get last 3 digits

	while(num)
	{
		r = num % 10;

		sum = sum + r;

		num = num / 10;
	}

	printf("%d \n", sum);

}

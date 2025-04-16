

//Sum of Digits

#include<stdio.h>
int main()
{
	int num,sum=0,r;

	printf("Enter a num : ");
	scanf("%d",&num);

	while(num)
	{
		r = num % 10;

		sum = sum + r;

		num = num / 10;
	}

	printf("%d \n", sum);

}

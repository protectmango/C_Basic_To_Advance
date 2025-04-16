


// Sum of Odd digits


#include<stdio.h>

int main()
{
	int num , r , sum=0 ;

	printf("Enter Number : ");
	scanf("%d",&num);

	while(num)
	{
		r=num%10;
		if(r&1)   //check if digit is odd
		sum +=r;

		num /=10;
	}

	printf("%d\n",sum);


}

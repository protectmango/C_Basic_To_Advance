

// Count digits in num


#include<stdio.h>

int main()
{
	int num, count=0;
	
	printf("Enter num : ");
	scanf("%d",&num);

	while(num)
	{
		num /=10;
		count++;
	}

	printf("%d\n",count);

	
}




// Count digits in num


#include<stdio.h>

int main()
{
	int num,r, count=0;
	
	printf("Enter num : ");
	scanf("%d",&num);

	while(num)
	{	
		r = num%10;
		num /=10;
	
		if(r&1) // check odd digits
		count++;
	}

	printf("%d\n",count);

	
}


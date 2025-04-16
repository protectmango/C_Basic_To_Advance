

// Count even more than 1 less than 7


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
	
		if(!(r&1)&&r>=1&&r<7) 
		count++;
	}

	printf("%d\n",count);

	
}


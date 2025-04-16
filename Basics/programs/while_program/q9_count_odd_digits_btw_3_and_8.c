

// Count odd more than 3 less than 8


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
	
		if(r&1&&r>=3&&r<8) 
		count++;
	}

	printf("%d\n",count);

	
}


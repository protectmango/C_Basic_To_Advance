#include<stdio.h>

int main()
{
	
	// Submitted By Gulshan Rana V24BE8G5
	int num,r,rev;

	printf("Enter a number : ");
	scanf("%d",&num);

	for (rev=0; num; num=num/10)
	{
		rev = rev*10 + num%10;
	}

	for (;rev;rev=rev/10)
	{
		r = rev%10;

		if(r==0)
			printf("zero ");
		else if(r==1)
			printf("one ");
		else if(r==2)
			printf("two ");
		else if(r==3)
			printf("three ");
		else if(r==4)
			printf("four ");
		else if(r==5)
			printf("five ");
		else if(r==6)
			printf("six ");
		else if(r==7)
			printf("seven ");
		else if(r==8)
			printf("eight ");
		else if(r==9)
			printf("nine ");
	}

	printf("\n");
}

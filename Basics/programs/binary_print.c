#include<stdio.h>

int main()
{
	int num ;
	int pos;

	printf("Enter a Number : ");
	scanf("%d", &num);

	printf("Binary of %d is : ",num);

	for(pos=31 ; pos >= 0 ; pos--)
		printf("%d ", num>>pos&1);

	printf("\n");

}

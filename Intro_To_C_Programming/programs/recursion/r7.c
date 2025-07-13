#include<stdio.h>

int countsetbit(int);
int main()
{
	unsigned int num;


	printf("Enter a number ");

	scanf("%d", &num);


	int result;

	result  = countsetbit(num);

	printf("Count : %d\n", result);
}


int countsetbit(int num)
{

	if(num==0)
		return 0;

	return num&1 + countsetbit(num>>1);
	
}

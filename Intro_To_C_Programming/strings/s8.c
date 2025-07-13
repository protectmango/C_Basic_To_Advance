#include<stdio.h>

int main()
{
	extern char i;
	i = 20;
	printf("%ld\n", sizeof(i));
}

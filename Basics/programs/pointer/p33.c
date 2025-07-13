#include<stdio.h>

int main()
{
	char str[]="hello, world\n";
	str[5] = '.';

	printf("%s",str);
}

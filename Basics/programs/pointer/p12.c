#include <stdio.h>
int main()
{
	char *s= "hello";
	char *p = s + 2;
	printf("%c\t%c\n", *p, s[1]);
}


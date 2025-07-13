#include<stdio.h>
int main()
{
	int a = 256;

	char *p= &a;

	*++p=3;

	printf("%d\n", a);

}

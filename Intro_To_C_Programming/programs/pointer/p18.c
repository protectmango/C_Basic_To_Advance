#include <stdio.h>
int main()
{
	int a[4] = {1, 2, 3, 4};
	char *p = &a[1];
	char *ptr = &a[2];
	int n = 1;
	n = ptr - p;
	printf("%d\n", n);
}


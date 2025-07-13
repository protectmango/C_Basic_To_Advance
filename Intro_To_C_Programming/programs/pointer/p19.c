#include <stdio.h>
int main()
{
	int *p = (int *)200;
	int *q = (int *)160;
	printf("%d\n", p - q);
}


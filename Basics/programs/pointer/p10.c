#include <stdio.h>
int main()
{
	const int ary[4] = {1, 2, 3, 4};
	int *p;
	p = ary + 3;
	*p = 55;
	printf("%d \n", ary[3]);
}


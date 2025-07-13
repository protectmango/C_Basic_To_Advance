#include <stdio.h>
int x = 0;
int main()
{
	int *const ptr = &x;
	printf("%p\n", ptr);
	ptr++;
	printf("%p\n", ptr);
}


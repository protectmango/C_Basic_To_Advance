#include<stdio.h>

//here we will have bus error because the data is stored in read only code section and "hello, world" is a literal.
int main()
{
	char *str="hello, world\n";
	str[5] = '.';

	printf("%s",str);
}

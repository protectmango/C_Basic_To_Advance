#include<stdio.h>
#include<string.h>
//this file will generate bus error because the string literals "hello world" is stored in read only data section or code section.
int main()
{

	char *str = "hello, world\n";
	char *str1 = "good morning\n";
	
	strcpy(str1, str);

	printf("%s\n",str1);
}

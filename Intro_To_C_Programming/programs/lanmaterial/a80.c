#include<stdio.h>
#include<string.h>
int main(void)
{
	char str1[]="Parul",str2[]="Devanshi";

	unsigned int i=-10;

	if(i<0)
		printf("i print \n");
	else
		printf("else print\n");

	if(strlen(str1)-strlen(str2) >=0 )
		puts(str1);
	else
		puts(str2);
	return 0;
}

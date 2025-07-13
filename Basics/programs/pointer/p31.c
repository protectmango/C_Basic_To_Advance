#include<stdio.h>
#include<string.h>

int main()
{
	char *str = "hello world\n";
	char strc[50]= "good morning india\n";

	strcpy(strc,str);

	printf("%s", strc);
}

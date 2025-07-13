#include<stdio.h>
int main()
{
	char p[] = "Hai friends",  *p1 = p;
	while(*p!='\0',printf("1"));
	++*p;
	printf("%s  %s\n",p,p1);
}


#include<stdio.h>
int main()
{
	char a[]="abcde";
	char *p=a;
	p++;
	p++;
	p[2]='z';
	printf("%s\n",p);
}

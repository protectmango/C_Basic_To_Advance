#include<stdio.h>
#include<string.h>

int main()
{
	char a[]="abcdef";
	char *ptr1 = a;
	ptr1 = ptr1+(strlen(ptr1)-1);
	printf("%c\n", --*ptr1--);
	printf("%c\n",--*--ptr1);
	printf("%c\n",--*(ptr1--));
	printf("%c\n",--*(--ptr1));
	printf("%c\n",*ptr1);
	printf("%s \n", a);   
}


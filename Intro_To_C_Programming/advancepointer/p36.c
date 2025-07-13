#include<stdio.h>
void main()
{
char ch='F';
int *p=ch;
printf("%u \n",p);
printf("%u \n",&ch);
printf("%u \n",&ch+'F');
printf("%u \n",p+'F');
}

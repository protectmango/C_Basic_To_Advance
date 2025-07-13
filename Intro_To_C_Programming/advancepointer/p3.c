#include<stdio.h>
void main()
{
int i=300,j=400;
char *p=&j;
short int **q=&p;
*q=&i;
++*q;
*--*q=*(p+1);
printf("%d\n",**q);
}

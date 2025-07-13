#include<stdio.h>
void main()
{
int i=400;
char *p=&i;
++p;
*p=0;
printf("%d\n",i);
}

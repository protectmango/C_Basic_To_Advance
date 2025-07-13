#include<stdio.h>
void main()
{
int i=500;
short int *p=&i;
++p;
*(p-1)=256;
printf("%d %d\n",*p,i);
}

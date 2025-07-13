#include<stdio.h>
void main()
{
int a[3][5]={321,322,323,325,326,327};
int (*p)[3]=a+1;
++*p;
printf(“%d\n”,*p);
}

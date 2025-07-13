#include<stdio.h>
void main()
{
int a[5]={10,20,30,40,50};
short int *p=a+1;
char *q=a;
++p;
p[-3]=33;
printf("%d",*q);
}

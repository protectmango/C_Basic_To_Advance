#include<stdio.h>

void main()
{
int a[5]={10,20,30,40,50};
char (*p)[3]= a+1;
p[-1][-1]=256;
*p=0;
printf(“%d,*p);
}

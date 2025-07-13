#include<stdio.h>
void main()
{
int i=10;
int *p=i;
printf("%d\n",(char *)p+1);
printf("%d\n",p+1);
}

#include<stdio.h>
int main()
{
int i=10;
int *p=i;
char **q=&p;
printf("%d\n",*q+1);
printf("%d\n",**q);
}

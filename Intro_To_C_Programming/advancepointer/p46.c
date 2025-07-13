#include<stdio.h>
void main()
{
int i=10;
char *p=i;
short int **q=&p;
printf("%d\n",p+1);
printf("%d\n",q+1);
printf("%d\n",*q+1);
}

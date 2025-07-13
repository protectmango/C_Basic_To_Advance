#include<stdio.h>
void main()
{
int i=400;
short int *p=&i;
char **q=&p;
*++*q=2;
q[0][-1]=0;
printf("%d\n",i);
}

#include<stdio.h>
void main()
{
short int a[10]={0,2,0,4,5};
char *p=a+1;
int **q=&p;
printf("%d\n",q[0][2]);
--*q;
printf("%d\n",q[0][1]);
}

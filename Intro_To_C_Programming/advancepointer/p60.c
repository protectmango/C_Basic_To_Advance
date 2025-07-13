#include<stdio.h>
void main()
{
int a[5]={400,500,600,700,712};
char *p=a+3;
short int **q=&p;
++*q;
short int (*r)[2]=p+1;
q++;
q[-1][1]=r[-1][-1];
printf(“%d\n”,a[4]);
}

#include<stdio.h>
void main()
{
int a[5]={10,20,30,40};
char *p[3]={a+2,a+1,a};
short int **q=p+1;
++*q;
printf("%d\n",q[1][1]);
printf("%d\n",q[0][-1]);
}

#include<stdio.h>
void main()
{
short int a[5]={100,200,300,400};
int *p[3]={a+4,a+3,a+2,a+1};
--p[0];
char **r=p+1;
r[-1][1]=2;
printf("%d\n",a[2]);
}

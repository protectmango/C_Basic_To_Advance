#include<stdio.h>
void main()
{
double a[5]={10,20,30,40,50};
char *p=a+1;
short int *q=a+4;
printf("%d\n",q-(short int *)p);
int **r=&p;
int **s=&q;
printf("%d\n",*s-*r);
}

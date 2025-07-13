#include<stdio.h>
void main()
{
int a[5]={10,20,30,40,50};
char *p=&a[1];
short int *q=&a[4];
short int **s=&p;
short int **b=&q;
printf("%d\n",*b-*s);
}

#include<stdio.h>
void main()
{
double a[5]={10,20,30,40,50};
char *p=a+1;
short int *q=p+20;
int **m=&p;
int **n=&q;
printf("%d",*n-*m);
}

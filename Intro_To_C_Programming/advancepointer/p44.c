#include<stdio.h>
void main()
{
extern double *p;
printf("%d\n",p+30);
}
double *p;

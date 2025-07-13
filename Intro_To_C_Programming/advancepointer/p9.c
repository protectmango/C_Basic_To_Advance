#include<stdio.h>
void main()
{
int a[2][5]={{65,66,67},{49,50,51,52}};
short int *q=a;
printf("%d\n",*q);
printf("%d\n",*(q+1));
}

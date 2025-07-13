#include<stdio.h>
void main()
{
short int a[5]={1,2,3,4,5};
int *p=a;
*p=258;
printf("%d %d\n",a[0],a[1]);
}

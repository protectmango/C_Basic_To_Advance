#include<stdio.h>
void main()
{
short int a[8]={120,240,360,480,600};
int (*p)[2]=a+1;
p[1][-2]=512;
printf(“%d %d\n”,a[1] ,a[2]);
}

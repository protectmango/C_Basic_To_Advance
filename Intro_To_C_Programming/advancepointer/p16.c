#include<stdio.h>
void main()
{
char a[6]={10,20,30,40,50,60};
short int (*p)[2]=a;
p[1][-1]=258;
printf("%d %d",a[2],a[3]);
}

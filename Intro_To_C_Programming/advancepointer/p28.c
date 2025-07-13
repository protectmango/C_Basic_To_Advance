#include<stdio.h>
void main()
{
int a[5]={10,20,30,40,50};
char (*p)[3]=a;
p[3][-4]=1;
printf("%d\n",a[1]);
}

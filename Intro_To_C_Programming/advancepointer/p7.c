#include<stdio.h>
void main()
{
int a[2][5]={{65,66,67},{49,50,51,52}};
short int (*p)[1]=a;
p[1][-1]=(a[1][0]<<8)|(a[1][1]);
printf("%d",**p);
}

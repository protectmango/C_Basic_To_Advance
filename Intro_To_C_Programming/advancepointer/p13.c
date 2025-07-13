#include<stdio.h>
void main()
{
int a[5]={'A','B','C','D','E'};
char (*p)[2]=a+1;
short int *q=a+1;
*q=50;
p[0][1]=51;
p[1][0]=52;
p[1][1]=53;
printf("%s",a+1);
}

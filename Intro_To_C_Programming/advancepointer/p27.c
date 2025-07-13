#include<stdio.h>
void main()
{
char a[10]="ABCDEFGH";
short int (*p)[2]=a;
p[2][-2]=49;
printf("%s\n",a);
}

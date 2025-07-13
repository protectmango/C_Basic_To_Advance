#include<stdio.h>
void main()
{
char a[12]="ABCDCDE12345";
int *p=a+8;
p[-1]=0;
char *q=a;
printf("%s %s\n",p,q+2);
}

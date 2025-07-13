#include<stdio.h>
void main()
{
char a[10]={'1','2','3','4','5'};
int (*p)[3]=a;
printf("%d",*(p+5)-*p);
}

#include<stdio.h>
void main()
{
int i=20;
short int *p=i;
int *q=i;
char *r=i;
printf("%d\n",p+1);
printf("%d\n",q+1);
printf("%d\n",r+1);
}

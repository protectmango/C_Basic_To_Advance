#include<stdio.h>
void main()
{
int a[5]={1,2,3,4,5};
char *p=a+1;
++p;
printf("%d \n",(*(&p))[5]);
}

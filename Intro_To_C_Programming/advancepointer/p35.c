#include<stdio.h>
void main()
{
int i=600;
short int *p=&i;
char *q=&i;
q=q+2;
*--q=1;
printf("%d \n",*p);
}

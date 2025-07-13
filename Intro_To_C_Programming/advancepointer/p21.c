#include<stdio.h>
void main()
{
int i=500,j=450,k=258;
short int *a[3]={&i,&j,&k};
char *p;
p=++*(a+2);
p[-1]=2;
printf("%d",k);
}

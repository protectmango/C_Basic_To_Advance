#include<stdio.h>
void main()
{
short int *a[3]={1000,2000,4000};
printf("%d",*(a+2)-*a);
}

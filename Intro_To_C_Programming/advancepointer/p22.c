#include<stdio.h>
void main()
{
int a[5]={1,2,3,4,5};
short int (*p)[4]=a;
printf("%u\n",a); printf("%u\n",p+4);
printf("%u",*p+4);
//Assume a as 1000 and predict your answer
}

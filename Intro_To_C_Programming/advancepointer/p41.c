#include<stdio.h>
void main()
{
int a[5]={48,57,56};
int *p=a;
*p|=49<<8|50<<16;
printf("%s \n",a);
}

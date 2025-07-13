#include<stdio.h>
void main()
{
char a[8]="ABCD";
short int *p=a;
p[2]=49|50<<8;
printf("%s \n",a);
}

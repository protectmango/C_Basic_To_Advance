#include<stdio.h>
void main()
{
int i=0;
char a[3][10]={"ABCDE","PQRSTUV","123456"};
short int( *p)[3]=a;
p[2][2]=p[4][0];
printf("%s",a[1]);
}

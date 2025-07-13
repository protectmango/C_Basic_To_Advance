#include<stdio.h>
void main()
{
char p[3][8]={"ABCDEF","PQRSTUV","123456"};
char *q=p+1;
p[1][2]=*q;
printf("%s",p[1]);
}

#include<stdio.h>
void main()
{
short int *p[3]={"ABCDEF","PQRSTUV","123456"};
char **q=p+1;
p[1][2]=**q;
printf("%s",p[1]);
}

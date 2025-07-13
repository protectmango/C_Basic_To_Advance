#include<stdio.h>

void main()
{
char s[ ][5]={“ABCD”,”PQRS”,”1234”};
char *p[3]={s[0],s[1],s[2]};
p[2][1]=’p’;
printf(“%s”,p[2]);
}

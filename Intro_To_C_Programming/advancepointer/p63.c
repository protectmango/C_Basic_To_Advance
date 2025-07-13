#include<stdio.h>
void main()
{
char s[3][10]={“ABCDEF”,”1234”,”PQRSTU”};
char (*p)[5]=s[0]+1;
char *q[3]={s[1]+1,s[2]+1,s[0]};
char **r=q+1;
p[1][0]=q[2][1];
q[2][7]=50;
r[1][8]=0;
printf(“%s\n”,s[0]);
}

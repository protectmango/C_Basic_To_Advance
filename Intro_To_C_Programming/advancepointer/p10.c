#include<stdio.h>
void main()
{
int i=0;
char a[3][10]={"ABCDE","PQRSTUV","123456"};
char *p[3]={a[0],a[1],a[2]};
char **q[3]={p,p+2,p+1};
for(i=1;a[1][i];i=i+2)
q[1][-1][i]=(48+i);
printf("%s",a[1]);
}

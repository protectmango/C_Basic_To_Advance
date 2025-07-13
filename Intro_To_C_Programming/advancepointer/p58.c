#include<stdio.h>
void main()
{
int i=301,j=401,k=501;
char *p[3]={&j,&k,&i};
*++p=&i;
printf("%d\n",p[1][0]);
}

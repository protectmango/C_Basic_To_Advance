#include<stdio.h>
void main()
{
int i=0;
char *p[3]={"ABCDE","PQRSTUV","12345"};
short int **q[3]={p+2,p+1,p};
++*--*q;
printf("%s",**q);
}

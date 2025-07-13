#include<stdio.h>
void main()
{
int i=400;
char *p=&i;
short int **q=&p;
*++*q=0;
printf("%d\n",**q);
printf("%d\n",q[0][-1]);
q[0][-1]=**q;
printf("%d",**q);
}

#include<stdio.h>
void main()
{
int i=300, j=322;
short int *p=&i;
char **q=&p;
short int ***r= &q;
++**r;
printf("%d\n",p[-1]);
printf("%d\n",p[0]);
}

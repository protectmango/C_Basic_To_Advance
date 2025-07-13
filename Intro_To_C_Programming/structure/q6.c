#include<stdio.h>
void sum(int *p)
{
char *q=p+1;
++*p;
++*q;
}
void main()
{
struct st
{
char j;
int i;
};
struct st b={10} ;
sum(&b.i);
printf("%d %d\n",b.i,b.j);
}

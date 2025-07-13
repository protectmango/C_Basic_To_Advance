#include<stdio.h>
struct st
{
char i;
int j;
}b={0,390};
void main()
{
b.i=b.j;
printf("%d\n",b.i);
}

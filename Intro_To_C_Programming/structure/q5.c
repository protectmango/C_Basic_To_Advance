#include<stdio.h>
void sum();
int main()
{
struct st
{
int i;
char j;
};
sum();
}
void sum()
{
struct st a;
a.i=10;
a.j=20;
printf("%d %d\n",a.i,a.j);
}

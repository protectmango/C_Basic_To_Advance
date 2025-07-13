#include<stdio.h>

struct st
{
int i;
int j;
int k;
};
int main()
{
struct st a={130,150,160},*p=&a;
char *q=&p->j;
printf("%d\n",*q);
}

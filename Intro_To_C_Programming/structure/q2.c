#include<stdio.h>
struct st
{
int i;
int j;
int k;
};
int main()
{
struct st a={130,150,160};
short int *p=&a.j;
p[-2]=250;
char *q=&a.i;
printf("%d\n",*q);
}

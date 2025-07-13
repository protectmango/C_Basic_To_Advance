#include<stdio.h>

struct st
{
int i;
char *p[3];
};
void main()
{
struct st a,*q=&a;
int b[5]={10<<24,20<<24,30<<24,40<<24,250};
q->p[0]=b+1;
q->p[1]=b+2;
q->p[2]=b+3;
printf("%d\n",*--q->p[1]);
}

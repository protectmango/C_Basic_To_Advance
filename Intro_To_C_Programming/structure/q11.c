#include<stdio.h>
struct st
{
int i;
char *p[3];
};

void main()
{
char ch=125,ch1=130,ch2=140;
struct st q[3],*a[3]={q+2,q+1,q+1};
--a[0];
q[0].i=10;
q[0].p[0]=&ch;
q[0].p[1]=&ch1;
q[0].p[2]=&ch2;
--a[0];
while(++*a[0]->p[0]>0);
printf("%d\n",*a[0]->p[0]);
}


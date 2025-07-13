#include<stdio.h>
void main()
{
short int a[2][5]={{10},{20,65}};
short int *p[3]={a[0],a[1],a[1]+1};
char **q[3]={p+2,p+1,p};
short int ***r=q+1;
++p[0];
--q[0];
r[-1][0][1]=a[1][1]^(1<<5);
printf(“%c\n”,p[0][5]);
}

#include<stdio.h>
void main()
{
short int a[5]={321,322,323};
short int *p=a+3;
char *q[3]={a+3,a+2,a+1};
- - *q;
q[0][0]=68;
short int (*r)[2]=a+2;
r[1][-1]=69|70<<8;
printf(“%s”,*r);
}

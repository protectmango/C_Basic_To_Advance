#include<stdio.h>
void main()
{
int a[5]={256,258,260,262,264};
char *p[3]={a+4,a+3,a+2};
short int **q[3]={p+2,p+1,p};
short int ***r=q+1;
-- *--*r;
**r=**r+2;
printf(“%d”,r[0][0][0]);
}

#include<stdio.h>
void main()
{
int i=350,j=450,k=550;
short int * p[3]={&i,&j,&k};
++*(p+1);
printf("%d\n",p[1][-1]);
printf("%d\n",p[1][0]);
}

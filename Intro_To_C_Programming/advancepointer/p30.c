#include<stdio.h>
void main()
{
int i=300,j=400,k=500;
short int * p[3]={&i,&j,&k};
char **q[3]={p+2,p+1,p};
*(q+1)=p+2;
q[1][-1][1]=0;
printf("%d\n",j);
printf("%d\n",q[1][-1][0]);
}

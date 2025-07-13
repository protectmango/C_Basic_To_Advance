#include<stdio.h>
void main()
{
int i=300, j=600;
char *p[2]={&i,&j};
short int **q=p+1;
p[1][1]=0;
printf("%d",**q);
}

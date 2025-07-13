#include<stdio.h>
void main()
{
int a[6]={0};
short int *p[3]={a+2,a+1,a};
p[2][1]=65|66<<8;
char *q=a+1;
short int **r=&q;
r[0][-2]=49|50<<8;
printf("%s",a);
}

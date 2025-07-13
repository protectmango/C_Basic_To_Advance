#include<stdio.h>
int main()
{
int a[5]={320,321,322,323,324};
char *p=a+1;
short int **q=&p;
char ***r=&q;
r[0][0][-3]=68;
q[0][-1]=49|50<<8;
r[0][0][1]=0;
printf("%s",p-4);
return 0;
}

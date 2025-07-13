#include<stdio.h>
void main()
{
char s[10]="ABCDEPQ";
int *p=s;
short int **q=&p;
q[0][2]=50|49<<8;
printf("%s\n",s);
}

#include<stdio.h>
void main()
{
char *p[3]={“ABCD”,”PQRS”,”1234”};
p[1][0]=63;
printf(“%s”,p[1]);
}

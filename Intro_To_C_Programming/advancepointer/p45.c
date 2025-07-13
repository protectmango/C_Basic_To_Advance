#include<stdio.h>
int *p;
void main()
{
static int i;
if(i<5)
{
++p;
++i;
main();
printf("%d\n",p);
}
}

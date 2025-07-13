#include<stdio.h>
struct st
{
short int i;
char *p[3];
};
void main()
{
int i;
struct st a[3];
for(i=0;i<3;i++)
a[i].p[i]="Abcde"+i;
for(i=0;i<3;i++)
printf("%s\n",a[i].p[i]);
}

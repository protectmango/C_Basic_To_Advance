#include<stdio.h>
void main()
{
short int *p[3]={"ABCDE","PQRST","12345"};
p[1]="6789T";
printf("%s",p[1]+1);
}

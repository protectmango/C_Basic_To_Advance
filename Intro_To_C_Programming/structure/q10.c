#include<stdio.h>

struct st
{
	int i;
	int j;
	int k;
};	
void sum(struct st *p)
{
	p->j|=1<<7;
}

void main()
{
	struct st a={200,300,400};
	char *p=&a.j;
	sum(&a);
	printf("%d\n",*p);
}


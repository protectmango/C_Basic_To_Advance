#include<stdio.h>
     int main()
     {
	int const *p = 5;
	int q;
	p = &q;
	printf("%d",++(*p)); 
     }


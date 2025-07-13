#include<stdio.h>
#include<string.h>

int main()
{
	int i,n;
	char *x="Alice";
	n=strlen(x);
	*x=x[n];
	for(i=0;i<=n;i++)
	{
		printf("%s",x);
		x++;
	}
	printf("%s\n",x);
	return 0;
}


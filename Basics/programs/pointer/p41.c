#include<stdio.h>
int main()
{
	float f=23.5f;

	char *p, pos;

	
	for(p=(char *)&f,p=p+3;p>=(char *)&f; p--)
	{
	
		for(pos=7; pos>=0; pos--)
		{
			printf("%d", *p>>pos&1);
		}
		printf(" ");
	}

	printf("\n");

}

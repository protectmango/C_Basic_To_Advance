#include<stdio.h>

int main()
{

	int a=0x12345678; 
	void *ptr; 
	ptr=&a; 
	printf("0x%x\n",*(int *)&*&*(char *)ptr); 

}

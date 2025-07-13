#include<stdio.h>



int count(int *, int, int);

int main()
{
	int arr[] = {11,22,33,44,55,66,77,88,99};

	int size = sizeof(arr)/sizeof(arr[0]);
	int c = count(arr, size,0);


	printf("Count : %d\n", c);
}


int count(int *p ,int ele, int i)
{

	if(i>=ele)
		return 0 ;

	int currentcount = (p[i]>39 && p[i]<99 ) ? 1:0;

	return currentcount + count( p,ele,i+1);
	
}

#include<stdio.h>



int sumof3ele(int * , int , int);

int main()
{

	int a[] = {10,20,30,44,55,66};


	int ele = sizeof(a)/sizeof(a[0]);


	int sum = sumof3ele(a, ele,0);

	printf("Sum of 1st 3 elements : %d\n",sum);
}



int sumof3ele(int *p, int ele, int i)
{

	if(i>=3)
	{
		return 0;
	}

	int sum = p[i];

	return sum + sumof3ele(p, ele, i+1);
		
}

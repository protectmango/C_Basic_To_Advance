#include<stdio.h>


void reversearr(int *, int, int);

int main()
{

	int a[]= {10,20,30,44,55,66};


	int ele = sizeof(a)/sizeof(a[0]);


	for(int i =0 ; i<ele; i++)
	{
		printf("%d ",a[i]);
	}

	printf("\n");


	reversearr(a,0,ele-1);


	for(int i =0 ; i<ele ; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}


void reversearr(int *p, int i, int j)
{

	if(i>=j)
		return ;

	int temp;
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;

	reversearr(p,i+1, j-1 );


}

/*
WAP in C using Recursive function to count
char in given any string .
i/p: char s[20]=”123 aacc tata ”; , ch= ‘a’
o/p: count = 4

*/


#include<stdio.h>


int charcount(char * , char, int, int);


int main()
{

	char s[20] = "123 aacc tata ";
	

	char ch = 'a';

	int len;

	for(len=0; s[len];len++);

	int count = charcount(s,ch, 0,len-1);

	printf("Count :%d\n",count);
}



int charcount(char *s, char c , int i,int j)
{

	if(i>=j)
	{
		return 0;
	}


	int count = (s[i]==c ? 1 : 0);

	return count + charcount(s, c,i+1,j);
}



/*
WAP in C using Recursive fun to reverse string .
i/p: char s[20]=”123 abc 789”;
o/p: 987 cba 321
*/


#include<stdio.h>

void revstr(char * , int, int);


int main()
{

	char s[] = "123 abc 789";



	printf("Input : %s\n" ,s );

	int len;

	for(len=0;s[len];len++);
	revstr(s,0 ,len-1);

	printf("Ouput : %s\n", s);
}



void revstr(char *s, int i,int j)
{

	if(i>=j)
		return;

	char temp;
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;

	revstr(s,i+1, j-1);

}

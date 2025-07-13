/*
 8.
WAP in C using CLA to reverse string .

 i/p : ./a.out “123 789 CBA”
 o/p: ABC 987 321
 */

#include<stdio.h>
#include<stdlib.h>
void my_strrev(char *);
void my_strword(char *, char *);
char *my_strchr(char *, char);

int main(int argc , char **argv)
{
/*
	if(argc!=2)
	{
		printf("Usage : %s <string>", argv[0]);
		return 1;
	}

*/
	int len;

	for(len = 0; argv[1][len] ; len++);

	printf("Length of string is :%d\n", len);

	char *str = (char *)malloc(sizeof(char)*len);

	str = argv[1];
	printf("%s\n", str);

	my_strrev(str);
	printf("%s\n", str);


	//word reverse
	
	char *p, *q;

	p = str;

	while((q = my_strchr(p, ' '))!=NULL)
	{
		my_strword(p,q-1);
		p =q+1;
	}

	my_strrev(p);	
	printf("%s\n", str);

}


char * my_strchr(char *str, char ch)
{
	for(int i=0; str[i];  i++)
	{
		if(str[i]==ch)
			return &str[i]; 
	}

	return 0;
}

void my_strrev(char *str)
{
	int len, i, j;
	char t;

	for(len=0; str[len]; len++);
		
	for(i = 0 , j=len-1; i<j ; i++ , j--)
	{
		t= str[i];
		str[i] = str[j];
		str[j] = t;
	}


}

void my_strword(char *str1 , char *str2)
{
	char t;

	while(str1<str2)
	{
		t= *str1;
		*str1 = *str2;
		*str2 = t;

		str1++;
		str2--;
	}

}

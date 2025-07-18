/*
 WAP in C to count line , word and digit in file.

 -----i/p file------
 123 abc coding
 file c ds 789 sirji
-------$ ./a.out data
 o/p: no of line = 2 , word= 8 , digit= 6
 */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Len 1024
int main(int argc , char **argv)
{
	
	if(argc<2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}


	FILE *fp = fopen(argv[1], "r");
	
	if(fp==NULL)
	{
		printf("%s not found.\n", argv[1]);
		return 1;
	}


	char ch;
	int line = 0;
	int word = 0;
	int digit = 0;

	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n')
			line++;

		if(ch==' '||ch=='\n')
			word++;

		if(ch>='0'&&ch<='9')
			digit++;

	}

	fclose(fp);


	printf("Lines : %d\n", line);
	printf("Words : %d\n", word);
	printf("digits : %d\n", digit);

	return 0;
}

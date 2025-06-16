/*
 WAP in C to count total number of line in file using fgets() fun.

 -----i/p file------
 123 abc coding
 pawan sirji
 99 vector
 o/p: no. of line = 3 
 */
#include<stdio.h>
#include<stdlib.h>
#define Max_Line 1024

int main(int argc, char **argv)
{
	if(argc<2)
	{
		printf("Usage : %s <filename>\n",argv[0]);
		return 1;
	}

	FILE *file = fopen(argv[1], "r");

	if(!file)
	{
		printf("%s not found.\n",argv[1]);
		return 1;
	}


	long line = 0;

	char s[Max_Line];


	while(fgets(s, sizeof(s), file))
	{
		line++;
	}

	printf("Using fgets()\nTotal Lines : %ld\n", line);

	fclose(file);
	return 0;

}

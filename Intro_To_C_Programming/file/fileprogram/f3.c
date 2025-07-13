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

	char ch;

	long len =0, i=0;

	while((ch=fgetc(file))!=EOF)
	{
		if(ch=='\n')
		{
			if(len<i)
				len = i;
			i=0;
			printf("%d\n", ch);

		}
			printf("%c,%ld\n", ch,i);
		i++;
	}

	rewind(file);
	char *s = malloc(sizeof(char)*(len+1));

	while(fgets(s,(len+2), file))
	{
		line++;
	}

	printf("Using fgets()\nTotal Lines : %ld, Len : %ld\n", line, len);

	fclose(file);
	return 0;

}

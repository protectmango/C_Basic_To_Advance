/*
 Q10. WAP in C to replace one word with another word in file .
 -------$ ./a.out data hello coding
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int longest_line_and_total_lines(FILE *, int *);


int main(int argc, char **argv)
{
	if(argc!=4)
	{
		printf("Usage : %s <data> <word1> <word2>\n", argv[0]);
		return 1;
	}

	FILE *file = fopen(argv[1], "r");

	if(file == NULL)
	{
		printf("%s not found.\n",argv[1]);
		return 1;
	}

	// call a function which could find the number of lines 
	
	int total_lines = 0;

	int longest_line = longest_line_and_total_lines(file, &total_lines);

	printf("Longest line : %d, Total lines : %d\n", longest_line, total_lines);


	char **lines = (char **)malloc((sizeof(char *)*total_lines));

	int i;

	for(i=0; i<total_lines; i++)
	{
		lines[i] = (char *)malloc(sizeof(char)*(longest_line+1));
	}
	
	for(i=0; i< total_lines; i++)
	{
		fgets(lines[i],(longest_line + 1), file);
	}

	for(i=0; i<total_lines; i++)
	{
		if(strstr(lines[i],argv[2]))
		printf("%s",lines[i]);
	}



	fclose(file);

}


int longest_line_and_total_lines(FILE *file, int *total_lines)
{
	char ch;
	int i=0;
	int longest_line =0;

	while((ch=fgetc(file))!=EOF)
	{
		if(ch=='\n')
		{
			if(longest_line < i)
				longest_line = i;
			i=0;
			(*total_lines)++;
		}
		i++;
	}

	rewind(file);
	return longest_line;
}

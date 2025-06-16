/*
 Q11. WAP in C to convert all word 1st and last char as a capital in file .
 -----i/p file ------ ------ o/p file ------
 123 abc coding 123 AbC CodinG
 file ds 789 sirji FilE DS 789 SirjI
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int longest_line_and_total_lines(FILE *, int *);

int main(int argc, char **argv)
{

	if(argc!=2)
	{
		printf("Usage : %s <data>\n",argv[0]);
		return 1;
	}

	FILE *file  = fopen(argv[1] , "r");

	int total_lines = 0;

	int longest_line = longest_line_and_total_lines(file,&total_lines);

	printf("Longest Line : %d Total Lines : %d\n",longest_line , total_lines);


	char **line = (char **)malloc(sizeof(char *)*total_lines);

	int i;

	for(i=0; i<total_lines; i++)
	{
		line[i] = (char *)malloc(sizeof(char)*(longest_line +1));
	}

	for(i=0; i<total_lines; i++)
	{
		fgets(line[i],(longest_line +1), file);
	}

	for(i=0; i<total_lines; i++)
	{
		char *lineptr = line[i];

		for(int j =0 ; lineptr[j]; j++)
		{
		
			if(j==0&&lineptr[j]!=' '&&(((lineptr[i]>='a')&&( lineptr[i]<='z'))))
			{
				lineptr[j] = lineptr[j] - 32;
			}	
			else if(lineptr[j]==' '||lineptr[j]=='\0')
			{
				if(lineptr[j-1]>='a' && lineptr[j-1]<='z')
				lineptr[j-1] = lineptr[j-1] - 32;
				if(lineptr[j+1]>='a' && lineptr[j+1]<='z')
				lineptr[j+1] = lineptr[j+1] - 32;
			}
		}	
		printf("%s",line[i]);
	}

	fclose(file);


	FILE *newfile  = fopen(argv[1], "w");

	for(i=0; i < total_lines; i++)
	{
		fputs(line[i],newfile);
	}


	fclose(newfile);

	//free the dynamic allocated memory
	
	for(i=0 ; i< total_lines; i++)
	{
		free(line[i]);
	}
	free(line);
}


int longest_line_and_total_lines(FILE *file, int *total_lines)
{

	char ch;
	int i=0;

	int longest_line=0;


	while((ch=fgetc(file))!=EOF)
	{
	
		if(ch=='\n')
		{
			if(longest_line<i)
				longest_line = i;
			i=0;
			(*total_lines)++;
		}
		i++;
	}

	rewind(file);
	return longest_line;
}

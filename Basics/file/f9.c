/*
 Q9. WAP in C to delete line 1st and last line only in given any file using CLA.
--------$ ./a.out data 
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lineoperation(FILE *, int *);

int main(int argc, char **argv)
{
	if(argc!=2)
	{
		printf("Usage : %s <data>\n", argv[0]);
		return 1;
	}


	FILE *file = fopen(argv[1], "r+");

	int linecount = 0;

	int longestline = lineoperation(file,&linecount);



	//allocating dynamic memory
	
	char **lines = (char **)malloc(sizeof(char *)*linecount);

	int i  ;

	for(i=0; i<linecount; i++)
	{
		lines[i] =(char *)malloc(sizeof(char)*(longestline+1));
	}

	for(i=0; i<linecount; i++)
	{
		fgets(lines[i],(longestline + 1), file);
	}


	fclose(file);

	FILE *newfile = fopen(argv[1], "w");

	for(i=0;i<linecount; i++)
	{
		if(i!=0&&i!=(linecount-1))
		{
			fputs(lines[i], newfile);
		}
	}

	fclose(newfile);

	// Free the dynamically allocated memory
	
	for(i=0; i<linecount ; i++)
		free(lines[i]);
	free(lines);

	printf("Line 0 and %d deleted successfully\n", linecount-1);
}


int lineoperation(FILE *file , int *linecount)
{
	int longestline=0;
	
	int i=0;
	char ch;

	while((ch=fgetc(file))!=EOF)
	{
		if(ch == '\n')
		{
			if(longestline<i)
				longestline  = i;
			i=0;
			(*linecount)++;
		}
		i++;
	
	}
	rewind(file);
	return longestline;
}

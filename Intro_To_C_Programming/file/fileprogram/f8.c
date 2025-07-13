/*
 WAP in C to delete any line of given file .
--------$ ./a.out data line_no
 */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LenMax_count(FILE *,int *);

int main(int argc, char **argv)
{
	if(argc!=3)
	{
		printf("Usage: %s <data> <line_no>\n",argv[0]);

		return 1;	
	}

	FILE *file = fopen(argv[1], "r+");


	int linecount=0;


	int maxlen = LenMax_count(file, &linecount);

	int i;


	char **lines = (char **)malloc(sizeof(char*)*(linecount));

	for (int i = 0; i < linecount; i++) 
	{
        lines[i] = (char *)malloc(sizeof(char) * (maxlen + 1));
	}

	for(i=0;i < linecount ; i++)
		fgets(lines[i], maxlen+1, file);

	fclose(file);//close the previous pointer 

	//open the file in w mode so the previous data get truncate (become 0) when open

	FILE *newfile = fopen(argv[1],"w");
	
	// deletion of line 
	int index = atoi(argv[2]) - 1;
	for(i=0;i<linecount ; i++)
	{
		if(i!= index)
		fputs(lines[i],newfile);
	}

	fclose(newfile);


	//free the dynamic allocated memory
	
	for(i=0 ; i< linecount; i++)
	{
		free(lines[i]);
	}
	free(lines);

	printf("Line deleted successfully\n");

}

int LenMax_count(FILE *p, int *count)
{

	int maxlen=0, i=0;

	char ch;
	while((ch=fgetc(p))!=EOF)
	{
		i++;
		if(ch=='\n')
		{
			if(i>maxlen)
				maxlen = i;
			i=0;
			(*count)++;
		}
	}
	rewind(p);
	return maxlen;
}

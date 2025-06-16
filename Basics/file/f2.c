/*
 WAP in C to convet small to capital later , using fseek function .
--------$ ./a.out data
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc , char **argv)
{

	if(argc < 2)
	{
		printf("Usage : %s <filename>\n", argv[0]);
		return 1;
	}

	FILE *file  = fopen(argv[1], "r+");
	

	if(!file)
	{
		printf("%s not found.\nPlease check the name.\n", argv[1]);
		return 1;	
	}


	char c;
	long pos;
	while((c = fgetc(file) )!= EOF)
	{
		if(islower(c))
		{
			printf("%c",c);
			pos = ftell(file);
			fseek(file, -1, SEEK_CUR);
			fputc(toupper(c), file);
			fseek(file, pos, SEEK_SET);
		}
	}

	printf("File converted to Upper Case\n");
	fclose(file);
}

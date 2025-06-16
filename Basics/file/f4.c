/*
 WAP in C to print all word length .
 --- i/p file----
 123 abc coding
 file sirji FILE
-------$ ./a.out data
 o/p : 3 3 6 4 5 4 
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char **argv)
{
	if(argc<2)
	{
		printf("Usage : %s <filename>\n", argv[0]);
		return 1;
	}

	FILE *file = fopen(argv[1], "r");

	if(!file)
	{
		printf("%s not found.\n", argv[1]);
		return 1;
	}

	char s[1024];
	while(fgets(s, sizeof(s), file))
	{
		for(int i = 0, wordlen = 0 ; i<= strlen(s); i++)
		{
			if(s[i]!=' '&&s[i]!='\n')
			{
				wordlen++;
			}


			if(s[i]==' '||s[i]=='\n')
			{
				printf("%d ", wordlen);
				wordlen = 0;
			}
		}
	}
		
	printf("\n");

	fclose(file);

}

/*
WAP in C to merge word by word in 3rd file , using fscanf() fun.
---------$ ./a.out data1 data2 data3 
*/

#include<stdio.h>

int main( int argc, char **argv)
{
	if(argc<4)
	{
		printf("Usage : %s <data1> <data2> <data3>.\n",argv[0]);
		return 1;
	}

	FILE *file1 = fopen(argv[1] , "r");
	FILE *file2 = fopen(argv[2] , "r");
	FILE *file3 = fopen(argv[3] , "w");

	if(!file1)
	{
		printf("%s not found.\n",argv[1]);
		return 1;
	}
	if(!file2)
	{
		printf("%s not found.\n",argv[2]);
		return 1;
	}
	if(!file3)
	{
		printf("%s not found.\n",argv[3]);
		return 1;
	}


	char s1[20], s2[20] ;

	while(fscanf(file1 , "%s", s1)!=EOF && fscanf(file2, "%s", s2)!=EOF)
	{
		fprintf(file3 , "%s", s1);
		fputc(' ', file3);
		fprintf(file3 , "%s", s2);
		fputc(' ', file3);
	}	
	fputc('\n', file3);
	fclose(file1);
	fclose(file2);
	fclose(file3);


}

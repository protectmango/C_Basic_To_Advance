/*
Q7. WAP in C to merge line by line in 3rd file , using fgets() fun.
 ---------$ ./a.out data1 data2 data3 
 */

#include<stdio.h>
#include<stdlib.h>

int maxlen(FILE *);

int main(int argc, char **argv)
{
	if(argc!=4)
	{
		printf("Usage : %s <data1> <data2> <data3>\n", argv[0]);
		return 1;
	}

	FILE *file1 = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "r");
	FILE *file3 = fopen(argv[3], "w");

	if(!file1)
	{
		printf("%s not found\n",argv[1]);
		return 1;
	}
	if(!file2)
	{
		printf("%s not found\n",argv[2]);
		return 1;
	}
	if(!file3)
	{
		printf("%s not found\n",argv[3]);
		return 1;
	}


	int len1 , len2;

	len1 = maxlen(file1);
	len2 = maxlen(file2);

	int maxlen = len1>len2 ? len1 : len2;



	char *p = malloc(maxlen + 1);
	char *q = malloc(maxlen + 1);
	

	while((fgets(p, maxlen+1 ,file1)!=NULL) &&(fgets(q,maxlen+1, file2)!=NULL) )
	{
		fputs(p,file3);
		fputs(q,file3);
	}




	fclose(file1);
	fclose(file2);
	fclose(file3);
}


int maxlen(FILE *file)
{

	int maxlen=0, i=0;
	char ch;
	while((ch=fgetc(file))!=EOF)
	{
		i++;
		if(ch=='\n')
		{
			if(maxlen < i)
				maxlen = i;
			i=0;
		}
	}
	rewind(file);
	return maxlen;
}

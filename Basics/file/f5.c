/*
 WAP in C merge char by char in 3rd file , using fgetc() fun.
----- data1--- .....data2....... -----data3-----
abcd pqr            123 789           a1b2c3d p7q8r9
 ---------$ ./a.out data1 data2 data3 
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc, char **argv)
{
	if(argc<3)
	{
		printf("Usage : %s <data1> <data2> <data3>\n",argv[0]);
		return 1;
	}

	FILE *file1 = fopen(argv[1],"r");
	FILE *file2 = fopen(argv[2],"r");

	FILE *file3 = fopen(argv[3],"w");

	if(!file1)
	{
		printf("%s not found.\n", argv[1]);
	}
	if(!file2)
	{
		printf("%s not found.\n", argv[2]);
	}

	char ch, ch1 , str[1024];
	while(((ch = fgetc(file1))!=EOF)&&((ch1 = fgetc(file2))!= EOF))
	{
		if(ch==' ')
		{
			ch=fgetc(file1);			
		}
		fputc(ch,file3);
		fputc(ch1,file3);
		printf("%c",ch1);
		printf("%c",ch);
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
}

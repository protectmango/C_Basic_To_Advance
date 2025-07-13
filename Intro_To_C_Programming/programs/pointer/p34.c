#include<stdio.h>

//size of arr and size of a character pointer
//
//considering str hold address
//where strarr is a array which hold character of size 1 byte
//

int main()
{

	char *str = "hello world";
	char strarr[] = "hello world";

	printf("size of str : %ld, size of strarr : %ld \n", sizeof(str), sizeof(strarr));

}

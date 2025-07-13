#include<stdio.h>

void main(int sizeofargv,char *argv[])

{

while(sizeofargv)

printf("%c ",*argv[--sizeofargv]);

}

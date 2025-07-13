#include<stdio.h>

/*
Why Do we use main()? 
Why should we write main()?
Can we write a program without main()?

main() is a function (the building block of C)

The program execution should start from a particular point,
the initial point is main 

Yes we can write a program without a main function but there are some alterations which we have to do at the time of compilation using gcc

if we write abc() instead of main() 

then to compile it using gcc

cmd : cc -nostartfiles  mainfunction.c

*/

int main() // Why Do we use main()
{
	printf("Hello World\n");
}


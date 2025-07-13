#include<stdio.h>

int main()
{
	char ch=300;
	printf("ch = %d\n",ch);
}


/*
 	Warning :

	overflow_char.c:5:10: warning: implicit conversion from 'int' to 'char' changes value from 300 to 44 [-Wconstant-conversion]
    5 |         char ch=300;
      |              ~~ ^~~


     	Output :

	ch = 44 
	-------------------------------------------

	Binary of 300 : 	|1|0|0|1|0|1|1|0|0|
				<-----9 bits ----->

	Memory of char: 1 byte only 8 bits available.

				  |0|0|1|0|1|1|0|0|
			  	      32 + 8+4 	
				  -----------------
	Result : 		  44  
*/

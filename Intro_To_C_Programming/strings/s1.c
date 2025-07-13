#include<stdio.h>

int main()
{
    char * string="*vector*" ;
    printf("%ld\n",sizeof(*string) ) ;
    printf("%ld\n",sizeof(string[1] ) ) ;
    return 0 ;
}

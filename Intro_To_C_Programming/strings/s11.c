#include <stdio.h>

int main() {
    char * p="hai sir",*p1 ; 
    while(*p)
        --*p++;
    printf("%s \n",p) ;
    return 0 ;
}

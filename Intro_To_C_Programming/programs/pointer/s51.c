/*
 Find the size of any datatype without using sizeof() using pointer
 */


#include <stdio.h>


int main() {
    // Example usage
    int a;
    printf("Size of int: %ld bytes\n", (char *)(&a +1) -(char *)(&a));
    
    double b;
    printf("Size of double: %ld bytes\n", GET_SIZE(b));
    
    char c;
    printf("Size of char: %ld bytes\n", GET_SIZE(c));
    
    struct { int x; char y; } s;
    printf("Size of struct: %ld bytes\n", GET_SIZE(s));
    
    return 0;
}

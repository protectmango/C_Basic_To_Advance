#include<stdio.h>

int main() {
    union u {
        int pawan;
        char c;
    } v={0xdef}; // Union variable 'v' initialized with 0xdef

    union u * SRH=&v; // Pointer SRH points to union 'v'

    v.c='a'; // Assign 'a' to the char member 'c'

    printf("%x \n", SRH->pawan); // Print the int member 'pawan' in hex
    return 0;
}

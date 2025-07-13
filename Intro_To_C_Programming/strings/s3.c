#include<stdio.h>

char * p[5]={"c","pawan","ds"}; // Global array of char pointers

int main() {
    printf("%c\n",++p[1][0]);
    return 0;
}

#include <stdio.h>
#include "utils.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void print_separator(void) {
    printf("\n" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" 
           "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" 
           "=" "=" "=" "=" "=" "=" "=" "=" "=" "=\n");
}


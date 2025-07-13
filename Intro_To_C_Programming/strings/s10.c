#include <stdio.h>

int main() {
    int i=11,j=22,k=33;
    int *p[3]={&i,&k,&j}; // Array of int pointers
    printf("%d \n",p[1][0]***p); // This expression has a typo/syntax error
    return 0;
}

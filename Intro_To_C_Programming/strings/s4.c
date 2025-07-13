#include<stdio.h>

int main() {
    int a=0, b=1, c=2, d;
    d=(a==0)||(b=10)&&(c=20);
    printf("%d %d \n",b,c);
    return 0;
}

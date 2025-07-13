#include<stdio.h>
void main()
char *p[3]={"abcde","12345","pqrstu"};
++*(p+1);
char **q[3]={p+1,p+2,p};
--*(q+1);
char ***r=q;
++*++r;
++*--*r;
printf("%s\n",**r);
}

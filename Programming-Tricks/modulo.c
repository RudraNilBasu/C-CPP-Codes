/*
Modulo with 2^n
READ - http://www.geeksforgeeks.org/optimization-techniques-set-1-modulus/
*/
#include<stdio.h>
int main()
{
    int n=87;
    int m=32; // power of 2 divisor with only one in binary form

    printf("%d MODULO %d = %d\n",n,m,(n&(m-1)));
}

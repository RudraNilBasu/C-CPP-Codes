//Source and Explanations - http://www.quora.com/Is-there-any-faster-way-to-check-if-a-number-is-in-the-power-of-two/answer/Vaibhav-Tulsyan

//A simple program to show a fast way to check if a positive number is a power of 2 or not.

#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    n=n&(n-1);
    if(n==0)
    {
        printf("The number is a power of 2\n");
    }
    else
    {
        printf("The number is NOT a power of 2\n");
    }
    return 0;
}

// EXPLANATIONS - A power of 2 Number N can be represented as 100000...000
// And N-1 will be 01111111...11111
// Performing Bitwise AND, We Will get the answer = 0 if N is a power of 2

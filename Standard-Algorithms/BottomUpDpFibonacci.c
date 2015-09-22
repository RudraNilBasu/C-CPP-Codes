/*
Program to find out nth Fibonacci number by Bottom Up DP
*/

#include<stdio.h>

int memo[100];

int fibo(int n)
{
    // To calculate Fibonacci of n by Bottom up DP method
    int i;
    for(i=1;i<=n;i++)
    {
        if(i<=2)
        {
            memo[i]=1;
        }
        else
        {
            memo[i]=memo[i-1]+memo[i-2];
        }
    }
}

int main()
{
    int n;
    for(n=0;n<100;n++)
    {
        memo[n]=0;
    }
    printf("Enter the number whose fibonacci you want to find (small numbers only)\n");
    scanf("%d",&n);
    fibo(n);
    printf("%d\n",memo[n]);
    return 0;
}

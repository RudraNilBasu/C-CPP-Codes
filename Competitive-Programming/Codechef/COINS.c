https://www.codechef.com/problems/COINS

#include<string.h>
#include<stdio.h>
#define inpint(x) scanf("%d",&x)
#define inpllu(x) scanf("%llu",&x)
#define input(x) scanf("%s",x)
#define RUNBF(i,a,b) for(i=a;i<b;i++)
#define RUN(i,a,b) for(i=a;i<=b;i++)
#define newline printf("\n")
#define printc(x) printf("%c",x)
#define printllu(x) printf("%llu\n",x)
#define RNB printf("Done by : Rudra Nil Basu\n")
#define llu unsigned long long int
#define MAX(a,b) ((a)>(b))?(a):(b)

llu memo[10000000]={0};

llu coins(llu n)
{
    if(n<12)
        return n;
    else
    {
        if((n>=0) && (n<10000000))
        {
            if(memo[n])
            {
                return memo[n];
            }
            else
            {
                llu s = (coins(n/2)+coins(n/3)+coins(n/4));
                memo[n]=MAX(n,s);
                return memo[n];
            }
        }
        else
        {
            llu s=(coins(n/2)+coins(n/3)+coins(n/4));
            return MAX(s,n);
        }
    }
}

int main()
{
    llu n;
    while(inpllu(n)!=EOF)
    {
        printllu(coins(n));
        newline;
    }
    return 0;
}

//http://www.spoj.com/problems/PRIME1/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <iostream>


#define MAX 1000000000
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))

using namespace std;

int sq1=sqrt(MAX);
int sq2=sqrt(sq1);

char prime[MAX+5];

int seive()
{
    MS1(prime);
    //1 is prime
    //0 is not prime
    int i,j;
    for(i=2;i<=sq2;i++)
    {
        if(prime[i])
        {
            for(j=(i*i);j<=sq1;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}

int segmentSeive(int a,int b)
{
    int lim=sqrt(b);
    int i,j;
    for(i=2;i<=lim;i++)
    {
        if(prime[i])
        {
            for(j=a-a%i;j<=b;j+=i)
            {
                if(j>=a && j!=i)
                {
                    prime[j]=0;
                }
            }
        }
    }
}

int main()
{
    seive();
    int t,m,i,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        if(n>sq2)
        {
            segmentSeive(m,n);
        }
        for(i=m;i<=n;i++)
        {
            if(prime[i] && i!=1)
            {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}

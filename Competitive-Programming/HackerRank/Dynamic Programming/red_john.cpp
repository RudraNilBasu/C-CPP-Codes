#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stdio.h>

#define ll long long int

using namespace std;
ll dp[41];

ll ways(int n)
{
    if(n<0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];

    if(n==0)
        return dp[n]=1;
    if(n<4)
        return dp[n]=ways(n-1);
    return dp[n]=ways(n-4)+ways(n-1);
}

int main() {
    int t,n,i,j;
    ll m;

    for(i=0;i<41;i++) {
        dp[i]=-1;
    }

    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        m=ways(n);


        // perform seive to find primes upto m
        int seive[m+1];
        for(i=0;i<m+1;i++) {
            seive[i]=1; // 1 meaning prime
        }
        for(i=2;i<m+1;i++) {
            for(j=i+i;j<m+1;j+=i) {
                seive[j]=0; // 0 meaning not prime
            }
        }
        ll count=0;
        for(i=2;i<=m;i++) {
            if(seive[i]) {
                count++;
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}

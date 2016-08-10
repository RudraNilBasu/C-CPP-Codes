#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stdio.h>

#define ll long long int
using namespace std;

ll memo[251][51];

ll calc(int sum, int current, int coins[])
{
    if(sum==0)
        return 1;

    if(sum<0)
        return 0;

    if(current<0)
        return 0;

    if(memo[sum][current]!=-1)
        return memo[sum][current];

    return memo[sum][current]=
        calc(sum, current-1, coins)
        +
        calc(sum-coins[current], current, coins);
}

int main() {
    int n,m,i,j;
    for(i=0;i<251;i++) {
        for(j=0;j<51;j++) {
            memo[i][j]=-1;
        }
    }
    scanf("%d %d",&n,&m);
    int coins[m];
    for(i=0;i<m;i++) {
        scanf("%d",&coins[i]);
    }
    printf("%lld\n",calc(n,m-1,coins));
    return 0;
}

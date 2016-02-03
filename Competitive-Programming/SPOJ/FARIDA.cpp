//http://www.spoj.com/problems/FARIDA/
#include<stdio.h>
#define ll long long
using namespace std;
int n;
long long int a[10001];
long long int dp[10001];
ll int MAX(ll int a, ll int b)
{
    if(a>b)
    return a;
    return b;
}
long long int coins(ll int a[], int i)
{
    if(i+1==n) return a[i];
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=MAX(
                     a[i]+coins(a,i+2),
                     coins(a,i+1)
                     );
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        int j;
        for(j=0;j<n;j++)
        {
            scanf("%lld",&a[j]);
        }
        for(j=0;j<10000;j++)
        {
            dp[j]=-1;
        }
        if(n==0)
        {
            printf("Case %d: 0\n",i);
        }
        else
        {
            printf("Case %d: %lld\n",i,coins(a,0));
        }
    }
    return 0;
}

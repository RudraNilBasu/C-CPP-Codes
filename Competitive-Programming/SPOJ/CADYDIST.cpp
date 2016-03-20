//http://www.spoj.com/problems/CADYDIST/
#include<stdio.h>
#include<algorithm>
#define ll long long int
using namespace std;
ll c[100001];
ll p[100001];
int main()
{
    ll n,i,res;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)    break;
        for(i=0;i<n;i++)
        scanf("%lld",&c[i]);
        for(i=0;i<n;i++)
        scanf("%lld",&p[i]);
        sort(c,c+n);
        sort(p,p+n);
        res=0;
        for(i=0;i<n;i++)
        {
            res+=c[i]*p[n-i-1];
        }
        printf("%lld\n",res);
    }
    return 0;
}

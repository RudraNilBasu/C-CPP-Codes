#include<stdio.h>
#define ll long long int
using namespace std;

ll calc(ll n, ll b, ll m)
{
    if(n==1) {
        return m;
    } else if(n<=0) {
        return 0;
    }
    if(n%2) {
        // odd
        return ((n+1)/2)*m + b + calc(n-((n+1)/2), b, 2*m);
    } else {
        // even
        return (n/2)*m + b + calc(n/2,b, 2*m);
    }
}

int main()
{
    int t;
    ll n,m,b;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld %lld",&n,&b,&m);
        printf("%lld\n",calc(n,b,m));
    }
    return 0;
}

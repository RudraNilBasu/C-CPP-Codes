//http://www.spoj.com/problems/ENIGMATH/
#include<stdio.h>
#define ll long long int
using namespace std;
ll gcd(ll a, ll b)
{
    if(a==0)
    return b;
    return gcd(b%a,a);
}
int main()
{
    int t;
    ll a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        ll n=gcd(a,b);
        while(n>1)
        {
            a/=n;
            b/=n;
            n=gcd(a,b);
        }
        printf("%lld %lld\n",b,a);
    }
    return 0;
}

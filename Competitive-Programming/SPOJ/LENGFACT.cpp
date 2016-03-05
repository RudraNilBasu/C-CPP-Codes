//http://www.spoj.com/problems/LENGFACT/
#include<stdio.h>
#include<math.h>
#define ll long long int
#define pi 3.141592653589793
using namespace std;
int main()
{
    int t;
    ll n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n<=3)
        {
            printf("1\n");
        }
        else
        {
            ll ans=ceil(log10(2*n*pi)/2+n*log10(n/2.7182818284590452353));
            printf("%lld\n",ans);
        }
    }
    return 0;
}

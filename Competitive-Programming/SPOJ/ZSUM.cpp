#include<stdio.h>
#define ll long long int
#define MOD 10000007
using namespace std;
ll k;
ll pw(ll x, ll y)
{
	// calculate x^y %MOD
	if(y==0) return 1;
	if(y==1) return x;
	if(y&1)
	{
		return (x*pw((x*x)%MOD,y/2))%MOD;
	}
	else
	{
		return pw((x*x)%MOD,y/2);
	}
}
int main()
{
	ll n,ans;
	while(1)
	{
		scanf("%lld %lld",&n,&k);
		if(n==0 && k==0) break;
		ans=(((2*pw(n-1,k))%MOD + (2*pw(n-1,n-1))%MOD)%MOD + (pw(n,k) + pw(n,n))%MOD)%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}

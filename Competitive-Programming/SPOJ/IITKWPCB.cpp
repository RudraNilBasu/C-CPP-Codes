#include<stdio.h>
#define ll long long int
using namespace std;
ll gcd(ll a, ll b)
{
	if(a==0) return b;
	return gcd(b%a,a);
}
int main()
{
	int t,found;
	ll n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		found=0;
		for(i=(ll)n/2;i>=1 && !found;i--)
		{
			if(gcd(i,n)==1)
			{
				printf("%lld\n",i);
				found=1;
			}
		}
	}
	return 0;
}

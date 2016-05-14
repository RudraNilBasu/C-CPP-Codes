#include<stdio.h>
#define ll long long int
using namespace std;
ll ab(ll a)
{
	if(a>0)
		return a;
	return a*-1;
}
int main()
{
	int t,n,i;
	ll lhs,rhs;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll a[n];
		lhs=rhs=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(n-(i+1)>0)
			{
				lhs+=(n-(i+1))*a[i];
				rhs+=(n-(i+1))*a[n-i-1];
			}
		}
		printf("%lld\n",ab(lhs-rhs));
	}
	return 0;
}

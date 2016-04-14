#include<stdio.h>
#include<algorithm>
#define ll long long int
using namespace std;
int main()
{
	ll t,i,n,j,sum=0;
	scanf("%lld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		int a[n],b[n];
		sum=0;
		for(j=0;j<n;j++)
		scanf("%d",&a[j]);
		for(j=0;j<n;j++)
		scanf("%d",&b[j]);
		sort(a,a+n);
		sort(b,b+n);
		reverse(b,b+n);
		for(j=0;j<n;j++)
		sum+=(a[j]*b[j]);
		printf("Case #%lld: %lld\n",i,sum);
	}
	return 0;
}

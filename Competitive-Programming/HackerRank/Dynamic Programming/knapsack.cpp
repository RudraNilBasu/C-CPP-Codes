#include<stdio.h>
#include<string.h>

#define ll long long int
using namespace std;

int n;
ll dp[2001];

ll max(ll a, ll b)
{
	if(a>=b)
		return a;
	return b;
}

ll knap(int a[], int c)
{
	if(dp[c]!=-1) {
		return dp[c];
	}

	int i;
	bool isFree=false;
	for(i=0;i<n;i++) {
		if(a[i]<=c) {
			isFree=true;
			break;
		}
	}
	if(!isFree) {
		return dp[c]=0;
	}

	ll res=-1;
	for(i=0;i<n;i++) {
		if(a[i]<=c) {
			res = max(
					res,
					a[i]+knap(a,c-a[i])
					);
		}
	}
	return dp[c]=res;
}

int main()
{
	int t,k,i;
	scanf("%d",&t);
	while(t--) {
		memset(dp,-1,sizeof(dp));
		scanf("%d %d",&n,&k);
		int a[n];
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		printf("%lld\n",knap(a,k));
	}
	return 0;
}

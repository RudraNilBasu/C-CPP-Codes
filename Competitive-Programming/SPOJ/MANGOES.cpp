#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define ll long long int

#define REAL 1
#define FAKE 0

bool isPrime[100000001];

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int main()
{
	int t;
	ll n,i,count;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		ll num=(n-1)/2;
		count=num*num;
		count=count%n;
		printf("%lld\n",count);
	}
	return 0;
}


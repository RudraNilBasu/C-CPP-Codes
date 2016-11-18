#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iostream>
#include<limits.h>

#define ll long long int
#define ull unsigned ll

#define PI 3.14159265
//#define DEBUG(X) cout << (X) << endl;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

// inputs
#define inpd(x) scanf("%d",&x)
#define inpc(x) scanf("%c",&x)

using namespace std;

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int max3(int a, int b, int c)
{
	return max(a,max(b,c));
}

ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
	return (a*b)/gcd(a,b);
}

ll min(ll a, ll b)
{
	if(a<=b)
		return a;
	return b;
}

int main()
{
	int t,n,i,j;
	ll l;
	ll mx;
	scanf("%d",&t);
	while(t--) {
		mx=LLONG_MAX;
		scanf("%d",&n);
		ll a[n];
		for(i=0;i<n;i++) {
			scanf("%lld",a+i);
		}
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				mx=min(mx,lcm(a[i],a[j]));
			}
		}
		printf("%lld\n",mx);
	}
	return 0;
}


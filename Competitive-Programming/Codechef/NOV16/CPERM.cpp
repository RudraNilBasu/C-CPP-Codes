#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iostream>

#define ll long long int
#define ull unsigned ll

#define PI 3.14159265
//#define DEBUG(X) cout << (X) << endl;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

// inputs
#define inpd(x) scanf("%d",&x)
#define inpc(x) scanf("%c",&x)

#define MOD 1000000007

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

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

ll ncrDP(int n, int r)
{
	int c[r+1];
	memset(c, 0, sizeof(c));
	c[0]=1;
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=min(i,r);j>0;j--) {
			c[j]=(c[j]+c[j-1])%MOD;
		}
	}
	return c[r];
}

ll ncr(int n, int r)
{
	//DEBUG(n)
	//DEBUG(r)
	if(r==0)
		return 1;
	int ni=n%MOD;
	int ri=r%MOD;
	return ( ncr(n/MOD, r/MOD)*ncrDP(ni,ri) )%MOD;
}

ll power(ll x, ll y)
{
	ll res=1;
	x=x%MOD;
	while(y>0) {
		//DEBUG(x)
		//DEBUG(y)
		//DEBUG(res)
		if(y&1) {
			//res=res*x;
			res=(res*x)%MOD;
		}
		y=y/2;
		//x=x*x;
		x=(x*x)%MOD;
	}
	return res;
}

int main()
{
	//ll x=((ll)pow(2,999))%MOD-2;
	//ll x=power(2,999);
	//DEBUG(x)
	int t;
	ll n,count,i;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		if(n<=1) {
			printf("0\n");
			continue;
		}
		// largest num is always in i
		// count+=(n-1)C(i-1)
		count=0;
		/*
		for(i=2;i<=n-1;i++) {
			// count = count + (n-2)C1 + (n-1)C(i-1)
			// update = count+=nCi-(n-2)C(i-2)
			//count=(count%MOD+ncr(n,i)%MOD-ncr(n-2,i-2)%MOD)%MOD;
			count=(count%MOD+ncr(n-1,i-1)%MOD)%MOD;
		}
		*/
		count=(power(2,n-1)-2)%MOD;
		//count=(power(2,n-1)%MOD-2%MOD)%MOD;
		printf("%lld\n",count);
	}
	return 0;
}


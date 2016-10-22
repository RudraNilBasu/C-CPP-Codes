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
#define DEBUG(X) cout << (X) << endl;

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

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int t,n,i,j,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		ll a[n];
		map<ll,int> mp;
		for(i=0;i<n;i++) {
			scanf("%lld",a+i);
			mp[ a[i] ]=1;
		}
		int flag=0;
		for(i=0;i<n && !flag;i++) {
			for(j=i+1;j<n && !flag;j++) {
				ll x=a[i]*a[j];
				if(mp[x]==0 || (x>1000000000) || (x<-1000000000)) {
					printf("no\n");
					flag=1;
					break;
				}
			}
		}
		if(!flag) {
			printf("yes\n");
		}
	}
	return 0;
}


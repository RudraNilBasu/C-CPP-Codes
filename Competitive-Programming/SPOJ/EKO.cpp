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

ll isPossible(ll ht, ll a[], ll n, ll m)
{
	// to check if we can get wood of value m
	// by cutting ht amt of height
	ll i;
	ll count=0;
	for(i=0;i<n;i++) {
		if(a[i]-ht>0) {
			count+=a[i]-ht;
		}
	}
	return count;
	//return count>=m;
}

int main()
{
	ll n,i;
	ll m;
	scanf("%lld %lld",&n,&m);
	ll a[n];
	for(i=0;i<n;i++) {
		scanf("%lld",a+i);
	}
	sort(a,a+n);
	ll low=a[0],high=a[n-1],mid;
	low=0;
	ll count;
	ll h=0;
	while(low<=high) {
		mid=(low+high)/2;
		//printf("low=%lld\tmid=%lld\thigh=%lld\n",low,mid,high);
		count=isPossible(mid,a,n,m);
		//if(isPossible(mid,a,n,m)) {
		if(count>m) {
			low=mid+1;
			if(mid>h) {
				h=mid;
			}
			//printf("IS possible with %lld. New Low=%lld\n",mid,low);
		} else if(count<m) {
			high=mid-1;
			//printf("NOT possible with %lld. New High=%lld\n",mid,high);
		} else {
			h=mid;
			//low=mid;
			break;
		}
	}
	printf("%lld\n",h);
	return 0;
}


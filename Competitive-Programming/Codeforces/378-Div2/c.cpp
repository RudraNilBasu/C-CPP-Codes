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
	int n,k,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) {
		scanf("%d",a+i);
	}
	scanf("%d",&k);
	ll b[k];
	for(i=0;i<k;i++) {
		scanf("%lld",b+i);
	}
	i=0;
	// if all values of b[] are not a subset of a[] then NO
	return 0;
}


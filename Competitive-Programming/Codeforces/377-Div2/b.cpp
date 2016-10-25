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
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n];
	int b[n];
	int i;
	for(i=0;i<n;i++) {
		scanf("%d",a+i);
		b[i]=a[i];
	}
	int walk=0;
	for(i=1;i<n;i++) {
		if(b[i-1]+b[i]<k) {
			b[i]=k-b[i-1];
			walk+=(b[i]-a[i]);
		}
	}
	printf("%d\n",walk);
	for(i=0;i<n;i++) {
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}


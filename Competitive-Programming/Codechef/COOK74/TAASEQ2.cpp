#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define ll long long int
#define MAX 2000000000

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int min(int a, int b)
{
	if(a<=b)
		return a;
	return b;
}

using namespace std;

int calc(int a[], int n)
{
	int i;
	int res=MAX;
	if(n<=3) {
		for(i=1;i<=n;i++) {
			res=min(res,a[i]);
		}
		return res;
	}
	// creating f[] and g[]
	bool f[n+2];
	f[0]=true;
	f[1]=true;
	f[2]=true;
	for(i=3;i<=n;i++) {
		f[i]=((a[i]-a[i-1])==(a[i-1]-a[i-2]))&&(f[i-1]);
	}
	bool g[n+2];
	g[n]=true;
	g[n-1]=true;
	g[n+1]=true;
	for(i=n-2;i>=1;i--) {
		g[i]=((a[i+1]-a[i])==(a[i+2]-a[i+1]))&&(g[i+1]);
	}
	// remove a[1]
	if(g[2]) {
		res = min(res,a[1]);
	}
	// remove a[2]
	if(g[3] && (a[3]-a[1])==(a[4]-a[3])) {
		res=min(res,a[2]);
	}
	// remove a[n]
	if(f[n-1]) {
		res=min(res,a[n]);
	}
	// remove a[n-1]
	if( f[n-2] && (a[n-2]-a[n-3])==(a[n]-a[n-2]) ) {
		res=min(res,a[n-1]);
	}
	for(i=3;i<=n-2;i++) {
		// eliminating i
		// check if left and right sides merge
		if( (a[i+1]-a[i-1])==(a[i-1]-a[i-2]) && 
				(a[i+2]-a[i+1])==(a[i+1]-a[i-1]) &&
				g[i+1] && f[i-1] 
				) {
			res = min(res,a[i]);
		}
	}
	if(res==MAX) {
		return -1;
	}
	return res;
}

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int a[n+1];
		for(i=1;i<=n;i++) {
			scanf("%d",a+i);
		}
		printf("%d\n",calc(a,n));
	}
	return 0;
}


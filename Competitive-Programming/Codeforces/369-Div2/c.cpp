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

#include<limits.h>
#define INF (ll)(1e18)

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

int n,m,k;
ll p[102][102];
int a[102];

int main()
{
	int i,j,x,y;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			cin>>p[i][j];
		}
	}
	ll dp[n+1][k+1][m+1];
	for(i=0;i<=n;i++) {
		for(j=0;j<=k;j++) {
			for(x=0;x<=m;x++) {
				dp[i][j][x]=INF;
			}
		}
	}
	if(a[1]==0) {
		for(i=1;i<=m;i++) {
			dp[1][1][i]=p[1][i];
		}
	} else {
		dp[1][1][a[1]]=0;
	}
	for(i=2;i<=n;i++) {
		for(j=1;j<=k;j++) {
			if(a[i]==0) {
				for(x=1;x<=m;x++) {
					//dp[i][j][x]=dp[i-1][j][x]+p[i][x];
					dp[i][j][x]=min(dp[i][j][x],dp[i-1][j][x]+p[i][x]);
					for(y=1;y<=m;y++) {
						if(y==x) continue;
						dp[i][j][x]=min(dp[i][j][x],dp[i-1][j-1][y]+p[i][x]);
					}
				}
			} else {
				dp[i][j][a[i]]=min(dp[i][j][a[i]],dp[i-1][j][a[i]]);
				for(x=1;x<=m;x++) {
					if(x==a[i]) continue;
					dp[i][j][a[i]]=min(dp[i][j][a[i]],dp[i-1][j-1][x]);
				}
			}
		}
	}
	ll ans=INF;
	for(i=1;i<=m;i++) {
		ans=min(ans,dp[n][k][i]);
	}
	if(ans==INF) {
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}


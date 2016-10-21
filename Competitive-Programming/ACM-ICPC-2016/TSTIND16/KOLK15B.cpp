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
#define DEBUG(X) cout << (X) << endl;

// inputs
#define inpd(x) scanf("%d",&x)
#define inpc(x) scanf("%c",&x)

//#define MAX 1000000007
#define MAX 1000000010


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
	int t,n,m,i,j;
	//inpd(t);
	cin>>t;
	//cin >>t;
	while(t--) {
		//inpd(n);
		//inpd(m);
		cin>>n>>m;
		int a[n][m];
		int up[n][m];
		int down[n][m];
		int left[n][m];
		int right[n][m];
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				//inpd(a[i][j]);
				cin>>a[i][j];
				if(i==0) {
					up[i][j]=a[i][j];
					//up[i][j]=min(0,a[i][j]);
				} else {
					up[i][j]=min(a[i][j],up[i-1][j]+a[i][j]);
					//up[i][j]=min(0,up[i-1][j]+a[i][j]);
				}
				if(j==0) {
					left[i][j]=a[i][j];
					//left[i][j]=min(0,a[i][j]);
				} else {
					left[i][j]=min(a[i][j],left[i][j-1]+a[i][j]);
					//left[i][j]=min(0,left[i][j-1]+a[i][j]);
				}
			}
		}
		for(i=n-1;i>=0;i--) {
			for(j=n-1;j>=0;j--) {
				if(i==n-1) {
					down[i][j]=a[i][j];
					//down[i][j]=min(0,a[i][j]);
				} else {
					down[i][j]=min(a[i][j],down[i+1][j]+a[i][j]);
					//down[i][j]=min(0,down[i+1][j]+a[i][j]);
				}
				if(j==m-1) {
					right[i][j]=a[i][j];
					//right[i][j]=min(0,a[i][j]);
				} else {
					right[i][j]=min(a[i][j],right[i][j+1]+a[i][j]);
					//right[i][j]=min(0,right[i][j+1]+a[i][j]);
				}
			}
		}
		// test
		/*
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				printf("%d ",up[i][j]);
			}
			printf("\n");
		}
		*/
		// test
		int dp[n][m];
		int ans=MAX;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				/*
				dp[i][j]=min(
						a[i][j],
						(up[i][j]+down[i][j]+left[i][j]+right[i][j]-(3*a[i][j]))
						);
					
				//dp[i][j]=min(a[i][j],a[i][j]+left[i][j-1]+right[i][j+1]+up[i-1][j]+down[i+1][j]);
				ans=min(ans,dp[i][j]);
				//ans=min(ans,(up[i][j]+down[i][j]+left[i][j]+right[i][j]-(3*a[i][j])));
				*/
				ans=min(ans,(up[i][j]+down[i][j]+left[i][j]+right[i][j]-3*a[i][j]));
			}
		}
		cout<<ans<<endl;
		//printf("%d\n",ans);
	}
	return 0;
}


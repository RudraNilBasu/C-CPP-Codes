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
#define SWAP(A,B) (A)=((A)+(B))-((B)=(A))

#define PI 3.14159265
//#define DEBUG(X) cout << (X) << endl;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define DEBUGL(x) std::cerr << "In " << __FILE__ << " at line " << __LINE__ << #x << ' = ' << x << std::endl;

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

ll c=0;

ll dp[101][2];

/*
int calc(int n, int k, int d, bool found)
{
	if(dp[n][k]!=-1) {
		c=(c+dp[n][k])%MOD;
		return dp[n][k];
	}
	int i;
	for(i=1;i<=k && i<=n;i++) {
		if(i==n && (found||i>=d)) {
			c=(c+1)%MOD;
			return dp[n][k]=1;
			//c=(c%MOD+1%MOD)%MOD;
		} else if(i==n && !found) {
			return dp[n][k]=0;
		}
		//if(i<n && no!=k) {
		if(i<n) {
			if(!found) {
				if(i>=d) {
					dp[n][k]=calc(n-i,k,d,true);
				} else {
					dp[n][k]=calc(n-i,k,d,false);
				}
			} else {
				dp[n][k]=calc(n-i, k, d, true);
			}
		}
	}
	return dp[n][k];
}
*/

ll calc(int n, int k, int d, bool found)
{
	if(dp[n][found]!=-1) {
		c=(c+dp[n][found])%MOD;
		return dp[n][found];
	}
	dp[n][found]=0;
	int i;
	for(i=1;i<=k && i<=n;i++) {
		if(i==n && (found||i>=d)) {
			c=(c+1)%MOD;
			return dp[n][found]=(dp[n][found]%MOD+1%MOD)%MOD;
			/*
			if(dp[n][k]==-1) {
				return dp[n][k]=1;
			} else {
				return dp[n][k]+=1;
			}
			*/
		} else if(i==n && !found) {
			return dp[n][found];
		}
		if(i<n) {
			if(!found) {
				if(i>=d) {
					dp[n][found]=(dp[n][found]%MOD+calc(n-i,k,d,true)%MOD)%MOD;
					/*
					if(dp[n][k]==-1) {
						dp[n][k]=calc(n-i,k,d,true);
					} else {
						dp[n][k]+=calc(n-i,k,d,true);	
					}
					*/
				} else {
					dp[n][found]=(dp[n][found]%MOD+calc(n-i,k,d,false)%MOD)%MOD;
					/*
					if(dp[n][k]==-1) {
						dp[n][k]=calc(n-i,k,d,false);
					} else {
						dp[n][k]+=calc(n-i,k,d,false);
					}
					*/
				}
			} else {
				dp[n][found]=(dp[n][found]%MOD+calc(n-i,k,d,true)%MOD)%MOD;
				/*
				if(dp[n][k]==-1) {
					dp[n][k]=calc(n-i, k, d, true);
				} else {
					dp[n][k]=calc(n-i, k, d, true);	
				}
				*/
			}
		}
	}
	return dp[n][k];
}

void comp(int n, int k, int d)
{
	memset(dp, 0, sizeof(dp));
	dp[0][0]=1; // no of ways to get n=0 with all edges are less than d
	int i,j;
	for(i=1;i<=n;i++) {
		dp[i][0]=0;
		for(j=1;j<=k;j++) {
			if(i<j)
				break;
			if(j<d) {
				dp[i][0]=(dp[i][0]%MOD+dp[i-j][0]%MOD)%MOD;
				dp[i][1]=(dp[i][1]%MOD+dp[i-j][1]%MOD)%MOD;
			} else {
				dp[i][1]=(dp[i][1]%MOD+dp[i-j][0]%MOD)%MOD;
				dp[i][1]=(dp[i][1]%MOD+dp[i-j][1]%MOD)%MOD;
			}
		}
	}
	cout<<dp[n][1]<<endl;
}

int main()
{
	int n,k,d;
	memset(dp, -1, sizeof(dp));
	c=0;
	scanf("%d %d %d",&n,&k,&d);
	comp(n,k,d);
	//calc(n,k,d,false);
	//cout<<c<<endl;
	return 0;
}


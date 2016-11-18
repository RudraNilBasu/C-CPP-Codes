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

#define MOD 1000000007

void getZarray(string str, int z[])
{
	int n=str.length();
	int L,R,k,i;
	L=R=0;
	for(i=1;i<n;i++) {
		if(i>R) {
			L=R=i;
			while(R<n && str[R-L]==str[R]) {
				R++;
			}
			z[i]=R-L;
			R--;
		} else {
			k=i-L;
			if(z[k]<R-i+1) {
				z[i]=z[k];
			} else {
				L=i;
				while(R<n && str[R-L]==str[R]) {
					R++;
				}
				z[i]=R-L;
				R--;
			}
		}
	}
}

ll dp[6000001];

ll calc(int pos, int z[], int n, int len)
{
	if(pos>=n)
		return 0;
	if(dp[pos]!=-1) {
		return dp[pos];
	}
	if(z[pos]!=len) {
		return dp[pos]=calc(pos+1, z, n, len);
	}
	if(z[pos]==len) {
		return dp[pos]=((1+calc(pos+len, z, n, len))%MOD+calc(pos+1, z, n, len)%MOD)%MOD;
	}
}

int main()
{
	int t;
	string str,pat;
	scanf("%d",&t);
	while(t--) {
		cin>>str;
		cin>>pat;
		string concat=pat+"$"+str;
		int l=concat.length();
		int z[l];
		getZarray(concat, z);
		memset(dp, -1, sizeof(dp));
		/*
		int i;
		for(i=pat.length()+1;i<l;i++) {
			printf("%d ",z[i]);
		}
		printf("\n");
		*/
		ll count=calc(pat.length()+1,z,l, pat.length());
		cout<<count<<endl;
	}
	return 0;
}


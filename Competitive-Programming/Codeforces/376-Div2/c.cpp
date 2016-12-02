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

int c[200001];
int hash[200001];
bool traversed[200001];
int mx=-1,num=0;

int dfs(int n, vector<int> *g, int parent)
{
	//cout<<"At node: "<<n<<" Color: "<<c[n]<<endl;
	hash[c[n]]++;
	if(hash[ c[n] ]>mx) {
		mx=hash[ c[n] ];
	}
	int i;
	for(i=0;i<g[n].size();i++) {
		if(g[n][i]==parent) {
			continue;
		}
		if(!traversed[ g[n][i] ]) {
			num++;
			traversed[ g[n][i] ]=true;
			dfs( g[n][i], g, n );
		}
	}
	return 0;
}

int main()
{
	int n,m,k;
	//cin>>n>>m>>k;
	scanf("%d %d %d",&n,&m,&k);
	//int c[n];
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",c+i);
		//cin>>c[i];
	}
	vector<int> g[n+1];
	//bool traversed[n+1];
	memset(traversed, false, sizeof(traversed));
	int l,r;
	for(i=0;i<m;i++) {
		scanf("%d %d",&l,&r);
		//cin>>l>>r;
		g[l].push_back(r);
		g[r].push_back(l);
	}
	int ans=0;
	for(i=1;i<=n;i++) {
		if(!traversed[i] && g[i].size()>0) {
			memset(hash, 0, sizeof(hash));
			mx=-1;
			num=1;
			traversed[i]=true;
			dfs(i,g, -1);
			//cout<<num<<' '<<mx<<endl;
			ans+=(num-mx);
		}
	}
	printf("%d\n",ans);
	//cout<<ans<<endl;
	return 0;
}


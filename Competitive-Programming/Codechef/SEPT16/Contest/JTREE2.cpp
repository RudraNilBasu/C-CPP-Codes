#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<limits.h>
 
#define ll long long int
 
int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}
 
using namespace std;
 
typedef struct node {
	int k;
	ll cost;
}node;
 
ll dp[1001][100001];
 
vector<node> cache[100001];
 
ll min(ll a, ll b)
{
	if(a<=b)
		return a;
	return b;
}
 
ll findMinCost(int city, vector<node> *cst, vector<int> *g, int k)
{
	if(city==1) {
		return 0;
	}
	if( city<=1000 &&  dp[city][k]!=-1 ) {
		return dp[city][k];
	} else if(city>1000) {
		int loop;
		for(loop=0;loop<cache[city].size();loop++) {
			if(cache[city][loop].k==k) {
				return cache[city][loop].cost;
			}
		}
	}
	// move to the next city with the current ticket
	//ll x=9999999;
	ll x=LLONG_MAX;
	if(k!=0) {
		x=findMinCost(g[city][0], cst, g, k-1);
	}
	// or drop the currentticket and take any of the 
	// tickets from this city
	int i;
	//printf("Current city %d size = %d\n",city, (int)cst[city].size());
	for(i=0;i<cst[city].size();i++) {
		x=min(
			x,
			cst[city][i].cost + findMinCost(g[city][0], cst, g, cst[city][i].k-1)
				);
	}
	if(city<=1000) {
		return dp[city][k]=x;
	} else {
		node _n;
		_n.k=k;
		_n.cost=x;
		cache[city].push_back(_n);
		return x;
	}
}
 
int main()
{
	int n,m,i,x,y;
	memset(dp,-1,sizeof(dp));
	scanf("%d %d",&n,&m);
	vector<int> g[n+1];
	for(i=1;i<=n-1;i++) {
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		//g[y].push_back(x);
	}
	vector<node> cst[n+1];
	for(i=1;i<=m;i++) {
		int _n;
		node _x;
		scanf("%d %d %lld",&_n, &_x.k, &_x.cost);
		cst[_n].push_back(_x);
	}
	/*
	printf("Cost chart:\n");
	for(i=1;i<=n;i++) {
		printf("City %d\n",i);
		int j;
		for(j=0;j<cst[i].size();j++) {
			printf("k=%d\tcost=%d\n",cst[i][j].k, cst[i][j].cost);
		}
	}*/
	int q,city;
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&city);
		printf("%lld\n",findMinCost(city, cst, g,0));
	}
	return 0;
}

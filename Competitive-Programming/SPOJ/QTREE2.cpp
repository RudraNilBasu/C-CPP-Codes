#include<stdio.h>
#include<vector>
#include<string.h>
#define edge pair< int,int >
#define ll long long int
using namespace std;
vector< pair<int,ll> > G[100001];
ll weight[100001];
int parent[100001][24];
int depth[100001];
int n;
int reset()
{
	int i;
	for(i=1;i<=n;i++) {
		G[i].clear();
	}
}
int dfs(int u, int p)
{
	// p = parent of node u
	parent[u][0]=p;
	depth[u]=depth[p]+1;
	int sz=G[u].size();
	int i;
	for(i=0;i<sz;i++) {
		int v=G[u][i].first;
		int w=G[u][i].second;
		if(v!=p) {
			weight[v]=weight[u]+w;
			dfs(v,u);
		}
	}
}
int pre()
{
	// pre compute the 2^i th parent
	// 2^i th parent of node j is stored at 
	// parent[j][i]
	// parent[j][0] is already computed in 
	// dfs()
	int i,j;
	for(i=1;(1<<i)<=n;i++) {
		for(j=1;j<=n;j++) {
			parent[j][i]=parent[parent[j][i-1]][i-1];
		}
	}
}
int lca(int u, int v)
{
	if(depth[u]<depth[v]) {
		int temp=v;
		v=u;
		u=temp;
	}
	// bringing them to the same depth
	int LOG=23;
	while(depth[u]!=depth[v]) {
		if( (depth[u]-(1<<LOG)) >= depth[v] ) {
			u=parent[u][LOG];
		}
		LOG--;
		if(LOG<0)
			LOG=0;
	}
	// bringing them to the same node
	LOG=23;
	while(u!=v) {
		if( parent[u][LOG]!=parent[v][LOG] || LOG==0 ) {
			u=parent[u][LOG];
			v=parent[v][LOG];
		}
		LOG--;
		if(LOG<0)
			LOG=0;
	}
	return u;
}
ll dist(int u, int v)
{
	int w=lca(u,v);
	return ((weight[u]+weight[v])-(2*weight[w]));
}
int kth(int u, int v, int k)
{
	int w=lca(u,v);
	int d1=depth[u]-depth[w]+1;
	int d2=depth[v]-depth[w]+1;
	int from;
	if(d1<k) {
		k=(d1+d2)-(k+1);
		from=v;
	} else if(d1==k) {
		return w;
	} else if(d1>k) {
		from=u;
		k-=1;
	}
	// finding the kth ancestor from "from" node
	int LOG=23;
	while(k!=0) {
		if( (1<<LOG) <= k ) {
			from=parent[from][LOG];
			k-=(1<<LOG);
		}
		--LOG;
		if(LOG<0)
			LOG=0;
	}
	return from;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		int i,j;
		reset();
		scanf("%d",&n);
		for(i=1;i<=n-1;i++) {
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			G[a].push_back(make_pair(b,c));
			G[b].push_back(make_pair(a,c));
		}
		dfs(1,0);
		pre();
		char op[5];
		while(1) {
			scanf("%s",op);
			if(strcmp(op,"DONE")==0) {
				break;
			} else if(strcmp(op,"DIST")==0) {
				int u,v;
				scanf("%d %d",&u,&v);
				printf("%lld\n",dist(u,v));
			} else if(strcmp(op,"KTH")==0) {
				int a,b,c;
				scanf("%d %d %d",&a,&b,&c);
				printf("%d\n",kth(a,b,c));
			}
		}
	}
	return 0;
}

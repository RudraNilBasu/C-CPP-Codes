#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;
#define ll long long int
#define edge pair< int, int >
#define MAX 100001
#define INF INT_MAX
struct comp {
	bool operator() (const edge &a, const edge &b) {
		return a.second > b.second;
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		priority_queue<edge,vector<edge>,comp> Q;
		vector<edge> G[MAX];
		int n,m,start,end;
		int i,j;
		scanf("%d %d %d %d",&n,&m,&start,&end);
		// input of the graph
		for(i=0;i<m;i++) {
			int u,v,wt;
			scanf("%d %d %d",&u,&v,&wt);
			G[u].push_back(edge(v,wt));
			G[v].push_back(edge(u,wt));
		}
		int dist[MAX]; // distance of a node from start
		bool spSet[MAX]; // visited or not
		for(i=0;i<=n;i++) {
			dist[i]=INF;
			spSet[i]=false;
		}
		dist[start]=0;
		Q.push(edge(start,0));
		while(!Q.empty()) {
			int x=Q.top().first;
			Q.pop();
			if( spSet[x] )
				continue;
			for(i=0;i<G[x].size();i++) {
				int y=G[x][i].first;
				int w=G[x][i].second;
				if( !spSet[y] && dist[y]>dist[x]+w ) {
					dist[y]=dist[x]+w;
					Q.push(edge(y,dist[y]));
				}
			}
			spSet[x]=true;
		}
		if(dist[end]==INF)
			printf("NONE\n");
		else
			printf("%d\n",dist[end]);
	}
	return 0;
}

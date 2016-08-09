#include<stdio.h>
#include<limits.h>

#define INF INT_MAX
using namespace std;

int main()
{
	int n,m,i,j,k,x,y,r;
	scanf("%d %d",&n,&m);
	int graph[n+1][n+1];
	for(i=0;i<n+1;i++) {
		for(j=0;j<n+1;j++) {
			graph[i][j]=INF;
			if(i==j && i!=0) {
				graph[i][j]=0;
			}
		}
	}
	for(i=0;i<m;i++) {
		scanf("%d %d %d",&x,&y,&r);
		graph[x][y]=r;
	}
	int dist[n+1][n+1];
	for(i=0;i<n+1;i++) {
		for(j=0;j<n+1;j++) {
			dist[i][j]=graph[i][j];
		}
	}
	for(k=0;k<n+1;k++) {
		for(i=0;i<n+1;i++) {
			for(j=0;j<n+1;j++) {
				if( dist[i][k]!=INF &&
						dist[k][j]!=INF &&
						dist[i][k]+dist[k][j]<dist[i][j] ) {
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--) {
		scanf("%d %d",&x,&y);
		if(dist[x][y]==INF) {
			printf("-1\n");
		} else {
			printf("%d\n",dist[x][y]);
		}
	}
	return 0;
}

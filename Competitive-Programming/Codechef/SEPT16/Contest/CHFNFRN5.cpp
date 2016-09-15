#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

int graph[1001][1001];
int h[1001][1001];

int main()
{
	int t,i,j,n,m,a,b,flag;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		memset(graph,-1, sizeof(graph));
		memset(h, -1, sizeof(h));
		while(m--) {
			scanf("%d %d",&a,&b);
			if(a==b) {
				continue;
			}
			graph[a][b]=1;
			graph[b][a]=1;
		}
		// create complement
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++) {
				if(graph[i][j]==-1 && j!=i) {
					h[i][j]=1;
				}
			}
		}
/*
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++) {
				printf("%d ",graph[i][j]);
			}
			printf("\n");
		}
		printf("---------\n");
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++) {
				printf("%d ",h[i][j]);
			}
			printf("\n");
		}
		*/
		// check if 2 colorable
		int color[n+1];
		memset(color, -1, sizeof(color));
		queue<int> q;
		q.push(1);
		color[1]=1;
		flag=1;
		while(1) {
			while(!q.empty()) {
				int u=q.front();
				q.pop();
				for(i=1;i<=n;i++) {
					if(h[u][i]!=-1 && color[i]==-1) {
						color[i]=1-color[u];
						q.push(i);
					} else if(h[u][i]!=-1 && color[i]==color[u]) {
						flag=0;
						break;
					}
				}
				if(!flag) {
					break;
				}
			}
			if(!flag) {
				break;
			}
			int x=-1;
			for(i=1;i<=n;i++) {
				if(color[i]==-1) {
					x=i;
					break;
				}
			}
			if(x==-1) {
				break;
			} else {
				q.push(x);
				color[x]=1;
			}
		}
		if(flag) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}

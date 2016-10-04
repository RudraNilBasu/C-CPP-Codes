#include<stdio.h>
#include<vector>
using namespace std;
//int graph[100001][100001];
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	//int graph[n+1][n+1];
	vector<int> g[n+1];
	for(i=0;i<m;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		//graph[x][y]=1;
		//graph[y][x]=1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int k=0;
	for(i=1;i<=n;i++) {
		/*
		int c=0;
		for(j=1;j<=n;j++) {
			if( graph[i][j]!=0 ) {
				c++;
			}
		}
		if( c==1 ) {
			k++;
		}
		*/
		if( g[i].size()==1 ) {
			k++;
		}
	}
	if(k>1) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	return 0;
}

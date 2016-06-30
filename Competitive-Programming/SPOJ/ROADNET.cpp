#include<stdio.h>
#include<limits.h>
#define INF INT_MAX
int graph[201][201];
int n;
int reset()
{
	int i,j;
	for(i=0;i<201;i++) {
		for(j=0;j<201;j++) {
			graph[i][j]=INF;
		}
	}
}
int input()
{
	int i,j;
	reset();
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			int x;
			scanf("%d",&x);
			graph[i][j]=x;
		}
	}
}
int floyd() {
	int d[n+1][n+1];
	int i,j,k;
	int redi[n+1],redj[n+1];
	int m=0;
	for(i=0;i<n+1;i++) {
		for(j=0;j<n+1;j++) {
			d[i][j]=graph[i][j];
		}
	}
	int flag=0;
	for(i=1;i<n+1;i++) {
		for(j=i+1;j<n+1;j++) {
			flag=0;
			for(k=1;k<n+1;k++) {
				if(k!=i && k!=j && d[i][k]+d[k][j]==d[i][j]) {
					flag=1;
				}
			}
			if(!flag) {
				printf("%d %d\n",i,j);
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		input();
		floyd();
	}
	return 0;
}

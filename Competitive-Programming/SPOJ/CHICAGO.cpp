#include<stdio.h>
#include<limits.h>
#define INF 0.0
int ab(int n) 
{
	if(n>0)
		return n;
	return -1*n;
}
int n;
int graph[101][101];
int kruskal() {
	double dist[n+1][n+1];
	int i,j,k;
	for(i=0;i<n+1;i++) {
		for(j=0;j<n+1;j++) {
			if(graph[i][j]==INF)
				dist[i][j]=INF*1.0;
			else
				dist[i][j]=(graph[i][j]*1.0)/100;
		}
	}
	for(k=0;k<n+1;k++) {
		for(i=0;i<n+1;i++) {
			for(j=0;j<n+1;j++) {
				if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j] < (dist[i][k]*dist[k][j]) && (i!=j) && j!=k && i!=k) {
					dist[i][j]=dist[i][k]*dist[k][j];
				}
			}
		}
	}
	printf("%.6lf percent\n",dist[1][n]*100.0);
}
int main()
{
	while(1) {
		int m,i,j;
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&m);
		//int graph[n+1][n+1];
		for(i=0;i<101;i++) {
			for(j=0;j<101;j++) {
				graph[i][j]=INF;
			}
		}
		for(i=0;i<m;i++) {
			int a,b,p;
			scanf("%d %d %d",&a,&b,&p);
			// storing the (100-p) on edge
			//p=100-p;
			graph[a][b]=p;
			graph[b][a]=p;
		}
		kruskal();
	}
	return 0;
}

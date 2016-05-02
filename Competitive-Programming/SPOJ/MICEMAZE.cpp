// Submit on SPOJ on C++14
#include<stdio.h>
#include<string.h>
#include<limits.h>
int n,e,t;
int a[101][101];
using namespace std;
int minDistance(int dist[], bool spSet[])
{
	int min=INT_MAX,minPos=-1;
	int i;
	for(i=1;i<=n;i++)
	{
		if(dist[i]<min && !spSet[i])
		{
			min=dist[i];
			minPos=i;
		}
	}
	return minPos;
}
int printRes(int dist[])
{
	int count=0,i;
	for(i=1;i<=n;i++)
	{
		if(dist[i]<=t) count++;
	}
	printf("%d\n",count);
}
int dijksktra(int e)
{
	int dist[n+1]; // min distance for node x is dist[x]
	bool spSet[n+1]; // if node x is traversed, spSet[n]=true
	int i,v;
	for(i=0;i<=n;i++)
	{
		dist[i]=INT_MAX;
		spSet[i]=false;
	}
	dist[e]=0;
	for(i=1;i<=n;i++)
	{
		int u=minDistance(dist,spSet); // to return the node with minimum distance
		spSet[u]=true; // traversing that node
		for(v=1;v<=n;v++)
		{
			if(!spSet[v] && a[u][v] && dist[u]!=INT_MAX && (dist[u]+a[u][v])<dist[v])
			{
				dist[v]=dist[u]+a[u][v];
			}
		}
	}
	printRes(dist);
}
int main()
{
	int m;
	memset(a,0,sizeof(a));
	scanf("%d %d %d %d",&n,&e,&t,&m);
	while(m--)
	{
		int i,j,c;
		scanf("%d %d %d",&i,&j,&c);
		a[j][i]=c;
	}
	dijksktra(e);
	return 0;
}

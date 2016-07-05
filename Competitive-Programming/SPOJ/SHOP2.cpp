#include<stdio.h>
#include<string.h>
#include<limits.h>
#define INF INT_MAX
using namespace std;
typedef struct cell {
	int x;
	int y;
}cell;
cell up,down,left,right;
int w,h;
int dist[26][26];
bool spSet[26][26];
char graph[26][26];
int isValid(cell pos)
{
	if(pos.x<0)
		return 0;
	if(pos.x>=h)
		return 0;
	if(pos.y<0)
		return 0;
	if(pos.y>=w)
		return 0;
	return 1;
}
cell add(cell a1, cell a2)
{
	cell sum;
	sum.x=a1.x+a2.x;
	sum.y=a1.y+a2.y;
	return sum;
}
cell findMin()
{
	int i,j,min=INF;
	cell res;
	res.x=-1;res.y=-1;
	for(i=0;i<h;i++) {
		for(j=0;j<w;j++) {
			if(min>dist[i][j] && !spSet[i][j]) {
				min=dist[i][j];
				res.x=i;
				res.y=j;
			}
		}
	}
	return res;
}
int dijkstra(cell start, cell end)
{
	int i,j;
	for(i=0;i<26;i++) {
		for(j=0;j<26;j++) {
			dist[i][j]=INF;
			spSet[i][j]=false;
		}
	}
	dist[start.x][start.y]=0;
	while(1) {
		//cell u = findMin((int **)spSet,(int **)dist); // find the node with min distance which is not traversed
		cell u = findMin();
		spSet[u.x][u.y]=true;
		//printf("Currently in Cell %d,%d\n",u.x,u.y);
		cell pos;
		pos = add(u,up);
		if( isValid( pos )==1 && graph[pos.x][pos.y]!='X' && !spSet[pos.x][pos.y] ) {
			if(graph[pos.x][pos.y]!='D' &&  dist[pos.x][pos.y] >dist[u.x][u.y]+(graph[pos.x][pos.y]-'0')) {
				dist[pos.x][pos.y] = dist[u.x][u.y]+(graph[pos.x][pos.y]-'0');
			} else if(graph[pos.x][pos.y]=='D') {
				dist[pos.x][pos.y] = dist[u.x][u.y];
			} //spSet[pos.x][pos.y]=true;
		}
		pos = add(u,right);
		if( isValid( pos )==1 && graph[pos.x][pos.y]!='X' && !spSet[pos.x][pos.y]) {
			if(graph[pos.x][pos.y]!='D'&&  dist[pos.x][pos.y] >dist[u.x][u.y]+(graph[pos.x][pos.y]-'0')) {
				dist[pos.x][pos.y] = dist[u.x][u.y]+(graph[pos.x][pos.y]-'0');
			} else if(graph[pos.x][pos.y]=='D'){
				dist[pos.x][pos.y] = dist[u.x][u.y];
			}//spSet[pos.x][pos.y]=true;
		}
		pos = add(u,left);
		if( isValid( pos )==1  && graph[pos.x][pos.y]!='X' && !spSet[pos.x][pos.y]) {
			if(graph[pos.x][pos.y]!='D'&&  dist[pos.x][pos.y] >dist[u.x][u.y]+(graph[pos.x][pos.y]-'0')) {
				dist[pos.x][pos.y] = dist[u.x][u.y]+(graph[pos.x][pos.y]-'0');
			} else if(graph[pos.x][pos.y]=='D'){
				dist[pos.x][pos.y] = dist[u.x][u.y];
			}//spSet[pos.x][pos.y]=true;
		}
		pos = add(u,down);
		if( isValid( pos )==1 && graph[pos.x][pos.y]!='X' && !spSet[pos.x][pos.y]) {
			if(graph[pos.x][pos.y]!='D'&&  dist[pos.x][pos.y] >dist[u.x][u.y]+(graph[pos.x][pos.y]-'0')) {
				dist[pos.x][pos.y] = dist[u.x][u.y]+(graph[pos.x][pos.y]-'0');
			} else if(graph[pos.x][pos.y]=='D') {
				dist[pos.x][pos.y] = dist[u.x][u.y];
			}//spSet[pos.x][pos.y]=true;
		}
		/*
		printf("-------\n");
		for(i=0;i<h;i++) {
			for(j=0;j<w;j++) {
				if(dist[i][j]==INF)
					printf("inf ");
				else
					printf("%d ",dist[i][j]);
			}
			printf("\n");
		}
		printf("------\n");

		for(i=0;i<h;i++) {
			for(j=0;j<w;j++) {
				printf("%d ",spSet[i][j]);
			}
			printf("\n");
		}
		printf("-------\n");
		*/
		if( spSet[end.x][end.y] ) {
			break;
		}
	}
	printf("%d\n",dist[end.x][end.y]);
}
int main()
{
	up.x=-1;up.y=0;
	down.x=1;down.y=0;
	left.x=0;left.y=-1;
	right.x=0;right.y=1;
	while(1) {
		int i,j;
		scanf("%d %d",&w,&h);
		if(w==0 && h==0)
			break;
		for(i=0;i<h;i++) {
			scanf("%s",graph[i]);
		}
		cell start,end;
		for(i=0;i<h;i++) {
			for(j=0;j<w;j++) {
				if(graph[i][j]=='S') {
					start.x=i;
					start.y=j;
				} else if(graph[i][j]=='D') {
					end.x=i;
					end.y=j;
				}
			}
		}
		dijkstra(start,end);
	}
	return 0;
}

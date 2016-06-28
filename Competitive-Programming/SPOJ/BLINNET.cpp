#include<stdio.h>
#include <vector>
#include <algorithm>
#define edge pair<int,int>
#define MAX 10001
using namespace std;

vector< pair<int,edge> > graph;
// of the form edge, weight

int parent[MAX];

int E; // total no of edges in the graph
int find_parent(int x) {
	if(x!=parent[x]) {
		parent[x]=find_parent(parent[x]);
	}
	return parent[x];
}
int kruskal()
{
	int total=0;
	int px,py;
	sort(graph.begin(),graph.end()); // sorting all the edges of the graph
	int i;
	for(i=0;i<E;i++) {
		//printf("Sorted : %d to %d\n",graph[i].second.first,graph[i].second.second);
		// finding the parent od the source and destination of each edge
		px=find_parent(graph[i].second.first);
		py=find_parent(graph[i].second.second);
		
		if(px!=py) {
			//printf("This one : %d to %d\n",graph[i].first.first,graph[i].first.second);
			// if they do not form a loop
			total+=graph[i].first;
			parent[px]=parent[py];
		}
	}
	return total;
}
int reset() {
	int i;
	for(i=0;i<MAX;i++) {
		parent[i]=i;
	}
	graph.clear();
}
int main()
{
	int s; // no of test cases
	int i,p,neigh,cost,sr;
	scanf("%d",&s);
	while(s--) {
		reset();
		E=0;
		int n; // no of cities
		scanf("%d",&n);
		for(i=0;i<n;i++) {
			char name[11]; // name of the city
			scanf("%s",name);
			scanf("%d",&p); // no of cities to which it is connected to
			while(p--) {
				scanf("%d %d",&neigh,&cost);
				graph.push_back(pair<int,edge>(cost,edge(i+1,neigh)));
				E++;
			}
		}
		printf("%d\n",kruskal());
	}
	return 0;
}

/*
Implementation of Kruskal's MST Algorithm
Ref - http://zobayer.blogspot.in/2010/01/kruskals-algorithm-in-c.html
*/
#include<stdio.h>
#include<vector>
#include<algorithm>

#define edge pair<int,int>
#define MAX 1001
using namespace std;
vector< pair<int,edge> > GRAPH,MST;
// it is of the form weight, edge

int parent[MAX];
int N,E,total;
int find(int x, int parent[])
{
    if(x!=parent[x])
    {
        parent[x]=find(parent[x],parent);
    }
    return parent[x];
}
int kruskal()
{
    int px,py,i;
    total=0;
    sort(GRAPH.begin(),GRAPH.end());
    for(i=0;i<E;i++)
    {
        px=find(GRAPH[i].second.first,parent);
        py=find(GRAPH[i].second.second,parent);

        if(px!=py)
        {
            MST.push_back(GRAPH[i]);
            total+=GRAPH[i].first;
            parent[px]=parent[py];
        }
    }
}
int reset()
{
    int i;
    for(i=0;i<MAX;i++)
    parent[i]=i;
}
int main()
{
    int i;
    scanf("%d %d",&N,&E);
    reset();
    for(i=0;i<E;i++)
    {
        int x,y,wt;
        scanf("%d %d %d",&x,&y,&wt);
        GRAPH.push_back(pair<int,edge>(wt,edge(x,y)));
    }
    kruskal();
    printf("Minimum Cost is %d\n",total);
    return 0;
}

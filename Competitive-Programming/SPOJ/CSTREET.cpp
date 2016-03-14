//http://www.spoj.com/problems/CSTREET/
#include<stdio.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define MAX 1001
#define edge pair<int,int>
using namespace std;
int parent[MAX];
int n; // no of nodes
ll m;  // no of edges

vector< pair<int,edge> > GRAPH,MST; // int = weight of the edge

ll find(int x, int *parent)
{
    if(x!=parent[x])
    {
        parent[x]=find(parent[x], parent);
    }
    return parent[x];
}

ll kruskal()
{
    ll i,total=0;
    // sorting the array on increasing order of the weight
    sort(GRAPH.begin(),GRAPH.end());

    for(i=0;i<m;i++)
    {
        ll px=find(GRAPH[i].second.first, parent);
        ll py=find(GRAPH[i].second.second, parent);

        if(px!=py)
        {
            // no cycles occured
            MST.push_back(GRAPH[i]);
            total+=GRAPH[i].first;
            parent[px]=parent[py];
        }
    }
    return total;
}
int reset()
{
    int i;
    for(i=0;i<=n;i++)
    {
        parent[i]=i;
    }
    return 0;
}
int main()
{
    int t,p,a,b,c;
    ll i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&p); // price for 1 furlong street
        scanf("%d %lld",&n,&m); // n = no of buildings (nodes) and m= no of streets (edges)
        reset();

        // clear the two vectors
        GRAPH.clear();
        MST.clear();

        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c); // a= source node b = destination node c= weight of path a-b
            GRAPH.push_back( pair<int,edge> (c,edge(a,b)) );
        }
        printf("%lld\n",p*kruskal());
    }
    return 0;
}

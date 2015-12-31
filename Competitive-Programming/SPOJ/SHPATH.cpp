//http://www.spoj.com/problems/TSHPATH/
//http://www.spoj.com/problems/SHPATH/
/*
Solution of both TSHPATH and SHPATH in SPOJ
Main Concepts - Using Map, the name of the cities and it's corresponding index is stored
The Vector of pair is used to represent the graph. Each pair contains the index and the weight of the path from the parent node
*/

#include<cstdio>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

bool visited[10010];
struct node
{
    int v; // the index of the node
    int d; // shortest distance
};
bool operator <(const node& a, const node& b)
{
    return (a.d>b.d);
}
int dijk(int src,int e,vector<pair<int,int> > adj[])
{
    priority_queue <node> q;
    struct node t,temp;
    int u,alt,v;
    int dist[10010]; // to hold the minimum distance

    memset(dist,127,sizeof(dist));
    memset(visited,false,sizeof(visited));

    dist[src]=0; // distance of the source is 0
    t.v=src;
    t.d=0;
    q.push(t);

    while(!q.empty())
    {
        t=q.top();
        q.pop();
        u=t.v; // the index of the node
        if(visited[u])
        {
            continue; // not visiting vertex which is visited
        }
        visited[u]=true;
        if(u==e)
        {
            break; // end is reached
        }
        for(int i=0;i<adj[u].size();i++)
        {
            v=adj[u][i].first;
            alt=t.d+adj[u][i].second;
            if(alt<dist[v])
            {
                dist[v]=alt;
                temp.v=v;
                temp.d=alt;
                q.push(temp);
            }
        }
    }
    return dist[e];
}
int main()
{
    int s,n;
    scanf("%d",&s);
    char str[12],name1[12],name2[12];
    while(s--)
    {
        map<string,int> names; // to hold the name of the city and it's corresponding index
        vector<pair<int,int> > adj[10010]; // vector of pairs. Each pair holds the node with which a specific node is connected and the weight of each node
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            names[str]=i; // storing the index in the 'str'th position
            int p; // no of neightbours
            scanf("%d",&p);
            for(int j=0;j<p;j++)
            {
                int v,w;
                scanf("%d %d",&v,&w);
                adj[i].push_back(make_pair(v-1,w));
            }
        }
        int r;
        scanf("%d",&r);
        for(int i=0;i<r;i++)
        {
            scanf("%s %s",name1,name2);
            printf("%d\n",dijk(names[name1],names[name2],adj));
        }
    }
    return 0;
}

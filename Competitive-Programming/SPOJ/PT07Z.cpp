//http://www.spoj.com/problems/PT07Z/

#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

vector<int> g[10000];
int dist[10000];
int n;  // the number of nodes

int bfs(int node) // Will perform BFS and will return the node whose distance is maximum from "node"
{
    queue<int> q;
    memset(dist,-1,sizeof dist);
    q.push(node);
    dist[node]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    int max=dist[node],max_node=node;
    for(int i=0;i<n;i++)
    {
        if(dist[i]>max)
        {
            max=dist[i];
            max_node=i;
        }
    }
    return max_node; // returning the node which is at a maximum distance from the root node
}

int main()
{
    scanf("%d",&n);
    int u,v;
    for(int i=0;i<n-1;i++)  
    {
        scanf("%d %d",&u,&v);
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    int node=bfs(0);
    node=bfs(node);
    printf("%d\n",dist[node]);
    return 0;
}

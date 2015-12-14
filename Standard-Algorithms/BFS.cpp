#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    vector<int> g[100];
    int u,v,dist[100],i,j,n,m;
    queue<int> q;
    for(i=0;i<100;i++)
    dist[i]=-1;
    cin>>n>>m;   // n - number of nodes     m - number of edges
    for(i=0;i<m;i++)
    {
        cin>>u>>v; // taking input
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dist[1]=0;
    q.push(1);//pushing the source which is taken as 1
    while(!q.empty())
    {
        u=q.front(); // taking the first value from queue
        q.pop();
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    for(i=1;i<=n;i++)
    cout<<dist[i]<<" ";
    return 0;
}

#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

vector<int> g[100];
int dfsnumb=0;

int DFS(int n,int *d)
{
    d[n]=dfsnumb;
    dfsnumb++;
    int i;
    for(i=0;i<g[n].size();i++)
    {
        if(d[g[n][i]]==-1)
        {
            DFS(g[n][i],d);
        }
    }
    return 0;
}
int main()
{
    int n,m,u,v,i;
    int dfs[100];
    cin>>n>>m;
    cout<<"Enter edges"<<endl;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(i=0;i<100;i++)
    {
        dfs[i]=-1;//all are unvisited
    }
    DFS(1,dfs);
    cout<<"DFS Traversal Result is :-"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<dfs[i]<<" ";
    }
    cout<<endl;
    return 0;
}

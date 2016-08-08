//https://www.hackerrank.com/challenges/bfsshortreach

#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int i,t,n,m,x,y,dist[1000],d[1000],s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        vector<int> g[1000];
        queue<int> q;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        scanf("%d",&s);
        for(i=0;i<1000;i++)
        {
            dist[i]=-1;
            d[i]=-1;
        }
        dist[s]=0;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(i=0;i<g[u].size();i++)
            {
                int v=g[u][i];
                if(dist[v]==-1)
                {
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(i==s)
            {
                continue;
            }
            else if(dist[i]==-1)
            {
                d[i]=-1;
                printf("%d ",d[i]);
            }
            else
            {
                d[i]=dist[i]*6;
                printf("%d ",d[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

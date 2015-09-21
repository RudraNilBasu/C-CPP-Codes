//https://www.codechef.com/problems/PD31

//Check whether it is connected
//check n=m-1
#include<cstdio>
#include <vector>
 
using namespace std;
 
vector<int> g[10000];
int dfsnumb=0;
 
int dfs(int n, int *d)
{
    d[n]=dfsnumb;
    dfsnumb++;
    int i;
    for(i=0;i<g[n].size();i++)
    {
        if(d[g[n][i]]==-1)
        {
            dfs(g[n][i],d);
        }
    }
    return 0;
}
 
int main()
{
    int n,m,u,v,i,dist[10001],f=0,x,y;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if((n-1)!=m)
    {
        printf("NO\n");
    }
    else
    {
        //checking for connectivity
        f=0;
        for(i=0;i<10001;i++)
        {
            dist[i]=-1;
        }
        dfs(x,dist);
        for(i=1;i<=n;i++)
        {
            if(dist[i]==-1)
            {
                f++;
                printf("NO\n");
            }
        }
        if(f==0)
        {
            printf("YES\n");
        }
    }
    return 0;
}
 

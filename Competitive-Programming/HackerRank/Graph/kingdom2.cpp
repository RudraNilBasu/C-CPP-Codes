#include<stdio.h>
#include<stdlib.h>
#include<vector>

#define MOD 1000000000
#define ll long long int

using namespace std;

vector<int> g[10001],rev[10001];
int visRev[10001];

bool isCycle(int v, bool visited[], bool recStack[])
{
    if(visited[v]==false) {
        visited[v]=true;
        recStack[v]=true;

        int i;
        for(i=0;i<g[v].size();i++) {
            if( !visited[g[v][i]] && isCycle(g[v][i], visited, recStack) ) {
                return true;
            } else if(recStack[g[v][i]]) {
                return true;
            }
        }
    }
    recStack[v]=false;
    return false;
}

bool isInfinite(int node, int n)
{
    bool visited[n+1];
    bool recStack[n+1];
    int i;
    for(i=0;i<n+1;i++) {
        visited[i]=false;
        recStack[i]=false;
    }
    for(i=1;i<=n;i++) {
        if(visRev[i]==-1) {
            continue;
        }
        if( isCycle(i,visited, recStack) ) {
            return true;
        }
    }
    return false;
}

ll ways(int start, int n)
{
    if(start==n) {
        return 1;
    }
    int i;
    ll c=0;
    for(i=0;i<g[start].size();i++) {
        /*
        if(isInfinite(g[start][i], n)) {
            printf("INFINITE PATHS\n");
            exit(0);
        } else {
            c = c % MOD + ways(g[start][i], n);
        }
        */
        if( visRev[ g[start][i] ]!=-1 ) {
            if(isInfinite(g[start][i], n)) {
                printf("Here %d\n",g[start][i]);
                printf("INFINITE PATHS\n");
                exit(0);
        } else {
            c = c % MOD + ways(g[start][i], n);
        }
        }
    }
    return c;
}

int dfs(int src, int vis[])
{
    vis[src]=1;
    int i;
    for(i=0;i<rev[src].size();i++) {
        if((vis[rev[src][i]]==-1)) {
            //vis[ rev[src][i] ] = vis[src]+1;
            dfs(rev[src][i], vis);
        }
    }
    return 0;
}

int main()
{
    int n,m,i,x,y;
    for(i=0;i<10001;i++) {
        visRev[i]=-1;
    }
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        rev[y].push_back(x);
    }

    dfs(n,visRev); // reverse DFS


    ll count=ways(1,n);
    printf("%lld\n",count);

    return 0;
}

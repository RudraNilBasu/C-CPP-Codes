#include<stdio.h>
#include<vector>
#define edge pair<int,int>
using namespace std;
int n,m;
vector<edge> graph[100001];
int floyd()
{
    int i,j,k;
    vector< pair<int,int> > dist[100001];
    for(i=1;i<=n;i++) {
        for(j=0;j<graph[i].size();j++) {
            dist[i].push_back( graph[i][j] );
        }
    }
    for(k=1;k<=n;k++) {
        for(i=1;i<n;i++) {
            for(j=0;j<graph[i].size();j++) {
                if(  )
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<m;i++) {
        int x,y,val;
        scanf("%d %d %d",&x,&y,&val);
        graph[x].push_back(pair<int,int>(y,val));
        graph[y].push_back(pair<int,int>(x,val));
    }
    floyd();
    return 0;
}

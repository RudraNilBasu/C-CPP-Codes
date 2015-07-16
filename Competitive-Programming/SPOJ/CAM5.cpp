//http://www.spoj.com/problems/CAM5/

#include <cstdio>
#include <vector>
#include <iostream>
 
using namespace std;
 
//vector <int> g[100000];
int dfsnumb=-1;
 
int DFS(int n,int *d,vector<int> (&g)[100000])
{
    dfsnumb++;
    d[n]=dfsnumb;
    int i;
    for(i=0;i<g[n].size();i++)
    {
        if(d[g[n][i]]==-1)
        {
            DFS(g[n][i],d,g);
        }
    }
}
 
int main ()
{
    int i,t,u,v,n,m,e,c=0;
    int d[100000];
    scanf("%d",&t);
    while(t--)
    {
        vector <int> g[100000];
        scanf("%d",&n);
        scanf("%d",&e);
        c=0;
        for(i=0;i<100000;i++)
        {
            d[i]=-1;
        }
        for(i=0;i<e;i++)
        {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        //DFS(0,d);
        //c++;
        for(i=0;i<n;i++)
        {
            if(d[i]==-1)
            {
                c++;
                //printf("hue %d\n",i);
                DFS(i,d,g);
                //i=-1;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
 

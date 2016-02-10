//http://www.spoj.com/problems/ANARC05B/
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<limits.h>
using namespace std;
int *a;
int dp[10001];
int negdp[10001];
inline int max(int a,int b)
{
    return (a>b)?a:b;
}
int dfs(vector<int> *g, int st, int end1, int end2,vector<int> *neg)
{
    if(st==end1)
    {
        if(st>0)
        {
            if(g[st].size()==0)
            {
                return end1;
            }
            else
            {
                return dp[st]=max(end1,end1+dfs(g,g[st][0],end1,end2,neg));
            }
        }
        else
        {
            if(neg[st].size()==0)
            {
                return end1;
            }
            else
            {
                return dp[st]=max(end1,end1+dfs(g,neg[st][0],end1,end2,neg));
            }
        }
    }
    if(st==end2)
    {
        if(st>0)
        {
            if(g[st].size()==0)
            {
                return end2;
            }
            else
            {
                return dp[st]=max(end2,end2+dfs(g,g[st][0],end1,end2,neg));
            }
        }
        else
        {
            if(neg[st].size()==0)
            {
                return end2;
            }
            else
            {
                return dp[st]=max(end2,end2+dfs(g,neg[st][0],end1,end2,neg));
            }
        }
    }
    if(st>=0)
    {
        if(dp[st]!=INT_MAX) return dp[st];
        if(g[st].size()==1)
        {
            return dp[st]= st+dfs(g,g[st][0],end1,end2,neg);
        }
        else if(g[st].size()==2)
        {
            return dp[st]= st+max(dfs(g,g[st][0],end1,end2,neg),dfs(g,g[st][1],end1,end2,neg));
        }
    }
    else
    {
        st*=-1;
        if(negdp[st]!=INT_MAX) return negdp[st];
        if(neg[st].size()==1)
        {
            return negdp[st]=(-1*st)+dfs(g,neg[st][0],end1,end2,neg);
        }
        else if(neg[st].size()==2)
        {
            return negdp[st]=(-1*st)+max(dfs(g,neg[st][0],end1,end2,neg),dfs(g,neg[st][1],end1,end2,neg));
        }
    }

}
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        vector<int> g[10001];
        vector<int> neg[10001];
        int i,st1,st2,end1,end2,x;
        for(i=0;i<10001;i++)
        {
            dp[i]=INT_MAX;
            negdp[i]=INT_MAX;
        }
        a=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        st1=a[0];
        end1=a[n-1];
        for(i=1;i<n;i++)
        {
            if(a[i-1]<0)
            {
                int x=-1*a[i-1];
                neg[x].push_back(a[i]);
            }
            else
            g[a[i-1]].push_back(a[i]);
        }
        scanf("%d",&n);
        a=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        st2=a[0];
        end2=a[n-1];
        for(i=1;i<n;i++)
        {
            if(a[i-1]<0)
            {
                int x=-1*a[i-1];
                neg[x].push_back(a[i]);
            }
            else
            g[a[i-1]].push_back(a[i]);
        }

        printf("%d\n",
               max(dfs(g,st1,end1,end2,neg),
                   dfs(g,st2,end1,end2,neg)
                   )
               );

    }
    return 0;
}

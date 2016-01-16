//http://www.spoj.com/problems/BITMAP/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <queue>
using namespace std;
int **ans;
int **ref;
char **a;
int n,m;
int bfs(int i,int j)
{
    queue<int> q;
    int qi,qj;
    q.push(i);
    q.push(j);
    while(!q.empty())
    {
        qi=q.front();
        q.pop();
        qj=q.front();
        q.pop();
        if(qi>0)
        {
            if(ans[qi-1][qj]==-1||ans[qi-1][qj]>(ans[qi][qj]+1) && ans[qi-1][qj]!=0)
            {
                ans[qi-1][qj]=ans[qi][qj]+1;
                q.push(qi-1);
                q.push(qj);
            }
        }
        if(qi<n-1)
        {
            if(ans[qi+1][qj]==-1 || ans[qi+1][qj]>(ans[qi][qj]+1) && ans[qi+1][qj]!=0)
            {
                ans[qi+1][qj]=ans[qi][qj]+1;
                q.push(qi+1);
                q.push(qj);
            }
        }
        if(qj>0)
        {
            if(ans[qi][qj-1]==-1 || ans[qi][qj-1]>(ans[qi][qj]+1) && ans[qi][qj-1]!=0)
            {
                ans[qi][qj-1]=ans[qi][qj]+1;//printf("hue\n");
                q.push(qi);
                q.push(qj-1);
            }
        }
        if(qj<m-1)
        {
            if(ans[qi][qj+1]==-1 || ans[qi][qj+1]>(ans[qi][qj]+1)&& ans[qi][qj+1]!=0)
            {
                ans[qi][qj+1]=ans[qi][qj]+1;
                q.push(qi);
                q.push(qj+1);
            }
        }
    }
    return 0;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        //queue<int>q;
        scanf("%d %d",&n,&m);
        a=(char **)malloc(n*sizeof(char *));
        ans=(int **)malloc(n*sizeof(int *));
        ref=(int **)malloc(n*sizeof(int *));
        for(i=0;i<n;i++)
        {
            a[i]=(char *)malloc(m*sizeof(char));
            ans[i]=(int *)malloc(m*sizeof(int));
            ref[i]=(int *)malloc(m*sizeof(int));
        }
        int k=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ans[i][j]=-1;
                ref[i][j]=k++;
            }
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                a[i][j]-=48;
                if(a[i][j]==1)
                {
                    ans[i][j]=0;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ans[i][j]==0)
                {
                    bfs(i,j);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

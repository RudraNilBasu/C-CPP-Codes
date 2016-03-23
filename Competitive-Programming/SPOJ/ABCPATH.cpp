//http://www.spoj.com/problems/ABCPATH/
#include<stdio.h>
#include<queue>
using namespace std;
int h,x;
char a[51][51];
int bfs(int i, int j)
{
    queue<int> q;
    q.push(i);
    q.push(j);

    int dist[h][x];

    int a1,b1,max=-1;
    for(a1=0;a1<h;a1++)
    {
        for(b1=0;b1<x;b1++)
        {
            dist[a1][b1]=-1;
        }
    }
    dist[i][j]=1; // marking initial point as 0
    max=dist[i][j];
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        j=q.front();
        q.pop();

        if(i!=0 && dist[i-1][j]==-1 && a[i-1][j]==(a[i][j]+1))
        {
            // checking for up
            q.push(i-1);
            q.push(j);
            dist[i-1][j]=dist[i][j]+1;
            if(dist[i-1][j]>max)
            {
                max=dist[i-1][j];
            }
        }
        if(i!=h-1 && dist[i+1][j]==-1 && a[i+1][j]==(a[i][j]+1))
        {
            // checking for down
            q.push(i+1);
            q.push(j);
            dist[i+1][j]=dist[i][j]+1;
            if(dist[i+1][j]>max)
            {
                max=dist[i+1][j];
            }
        }
        if(j!=0 && dist[i][j-1]==-1 && a[i][j-1]==(a[i][j]+1))
        {
            // checking left
            q.push(i);
            q.push(j-1);
            dist[i][j-1]=dist[i][j]+1;
            if(dist[i][j-1]>max)
            {
                max=dist[i][j-1];
            }
        }
        if(j!=x-1 && dist[i][j+1]==-1 && a[i][j+1]==(a[i][j]+1))
        {
            // checking right
            q.push(i);
            q.push(j+1);
            dist[i][j+1]=dist[i][j]+1;
            if(dist[i][j+1]>max)
            {
                max=dist[i][j+1];
            }
        }
        // check diagonal
        // south east
        if( (j!=x-1 && i!=h-1) && dist[i+1][j+1]==-1 && a[i+1][j+1]==(a[i][j]+1))
        {
            q.push(i+1);
            q.push(j+1);
            dist[i+1][j+1]=dist[i][j]+1;
            if(dist[i+1][j+1] > max)
            {
                max=dist[i+1][j+1];
            }
        }
        // south west
        if( (j!=0 && i!=h-1) && dist[i+1][j-1]==-1 && a[i+1][j-1]==(a[i][j]+1))
        {
            q.push(i+1);
            q.push(j-1);
            dist[i+1][j-1]=dist[i][j]+1;
            if(dist[i+1][j-1] > max)
            {
                max=dist[i+1][j-1];
            }
        }
        // north east
        if( (j!=x-1 && i!=0) && dist[i-1][j+1]==-1 && a[i-1][j+1]==(a[i][j]+1))
        {
            q.push(i-1);
            q.push(j+1);
            dist[i-1][j+1]=dist[i][j]+1;
            if(dist[i-1][j+1] > max)
            {
                max=dist[i-1][j+1];
            }
        }
        // north west
        if( (j!=0 && i!=0) && dist[i-1][j-1]==-1 && a[i-1][j-1]==(a[i][j]+1))
        {
            q.push(i-1);
            q.push(j-1);
            dist[i-1][j-1]=dist[i][j]+1;
            if(dist[i-1][j-1] > max)
            {
                max=dist[i-1][j-1];
            }
        }
    }
    return max;
}
int main()
{
    int i,j,ans,t=1;
    while(1)
    {
        scanf("%d %d",&h, &x);
        queue<int> q; // to store the i and j pos of 'A'
        if(h==0 && x==0) break;
        for(i=0;i<h;i++)
        {
            scanf("%s",a[i]);

            for(j=0;j<x;j++)
            {
                if(a[i][j]=='A')
                {
                    q.push(i);
                    q.push(j);
                }
            }
        }
        if(q.empty())
        {
            printf("Case %d: 0\n",t++);
            continue;
        }
        ans=-1;
        while(!q.empty())
        {
            i=q.front();
            q.pop();
            j=q.front();
            q.pop();
            ans=max(ans,bfs(i,j));
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

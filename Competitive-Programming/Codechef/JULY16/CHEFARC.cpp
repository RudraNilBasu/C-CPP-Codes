#include<stdio.h>
#include<queue>
#include<string.h>
#include<limits.h>
using namespace std;
typedef struct cell {
    int x;
    int y;
}cell;

int n,m;
bool isValid(cell num) {
    if(num.x<0)
        return false;
    if(num.y<0)
        return false;
    if(num.x>=n)
        return false;
    if(num.y>=m)
        return false;
    return true;
}

int main()
{
    int t,i,j,k1,k2;
    scanf("%d",&t);

    cell moves[4];

    moves[0].x=1;moves[0].y=0;
    moves[1].x=0;moves[1].y=1;
    moves[2].x=-1;moves[2].y=0;
    moves[3].x=0;moves[3].y=-1;

    while(t--) {
        scanf("%d %d %d %d",&n,&m,&k1,&k2);
        int a[n][m];
        int dist[n][m];
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                scanf("%d",&a[i][j]);
            }
        }
        memset(dist,-1,sizeof(dist));
        cell start;
        start.x=0;start.y=0;
        dist[0][0]=0;

        queue<cell> q;
        q.push(start);
        while(!q.empty()) {
            cell u=q.front();
            q.pop();
            for(i=0;i<4;i++) {
                cell temp;
                temp.x=u.x+moves[i].x;
                temp.y=u.y+moves[i].y;

                if( isValid(temp) && dist[temp.x][temp.y]==-1 && a[temp.x][temp.y]==0 ) {
                    dist[temp.x][temp.y]=dist[u.x][u.y]+1;
                    q.push(temp);
                }
            }
        }
        /*
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                printf("%d ",dist[i][j]);
            }
            printf("\n");
        }
        */

        // for 0,m-1
        int dist2[n][m];
        memset(dist2,-1,sizeof(dist2));
        //cell start;
        start.x=0;start.y=m-1;
        dist2[0][m-1]=0;

        queue<cell> q2;
        q2.push(start);
        while(!q2.empty()) {
            cell u=q2.front();
            q2.pop();
            for(i=0;i<4;i++) {
                cell temp;
                temp.x=u.x+moves[i].x;
                temp.y=u.y+moves[i].y;

                if( isValid(temp) && dist2[temp.x][temp.y]==-1 && a[temp.x][temp.y]==0 ) {
                    dist2[temp.x][temp.y]=dist2[u.x][u.y]+1;
                    q2.push(temp);
                }
            }
        }
        /*
        printf("--------------\n");
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                printf("%d ",dist2[i][j]);
            }
            printf("\n");
        }
        */
        int res[n][m];
        int ans=INT_MAX;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if( dist[i][j]==-1 || dist2[i][j]==-1 ) {
                    //continue;
                    res[i][j]=-1;
                } else {
                    res[i][j]=max(dist[i][j], dist2[i][j]);
                }
                if(res[i][j]!=-1 && ans>res[i][j]) {
                    ans=res[i][j];
                }
            }
        }
        /*
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                printf("%d ",res[i][j]);
            }
            printf("\n");
        }
        */
        if(ans==INT_MAX) {
            printf("-1\n");
        } else {
            printf("%d\n",ans);
        }
    }
}

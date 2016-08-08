#include<stdio.h>
#include<string.h>
using namespace std;
int graph[101][101];
int n,m;
int check(int node)
{
    // no of node in this tree (considering current node)
    int noOfNode=1;
    int i;
    for(i=0;i<=n;i++) {
        if( graph[node][i] ) {
            //noOfNode++;
            noOfNode+=check(i);
        }
    }
    return noOfNode;
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    memset(graph,0,sizeof(graph));
    for(i=0;i<m;i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x>y) {
            graph[y][x]=1;
        } else {
            graph[x][y]=1;
        }
        //graph[x][y]=1;
        //graph[y][x]=1;
    }
    int count=0;
    for(i=1;i<=n;i++) {
        for(j=0;j<n;j++) {
            if(graph[i][j] ) {
                // if a node exists
                // check if it is possible to make even tree by cutting i,j
                if( check(j)%2==0 ) {
                    graph[i][j]=0;
                    count++;
                }
            }
        }
    }
    printf("%d\n",count);
    return 0;
}

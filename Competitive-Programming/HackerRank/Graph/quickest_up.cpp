#include<stdio.h>
#include<string.h>
#include<vector>
#include<limits.h>

#define MAX 101
#define MAX_NODES 100
using namespace std;

typedef struct cell{
    int dest;
    int cost;
}cell;

vector<int> graph[MAX];
int shortest_path[MAX];
bool spSet[MAX];

void initialise()
{
    //memset(shortest_path,INT_MAX, sizeof(shortest_path));
    //memset(shortest_path,100000, sizeof(shortest_path));
    //memset(spSet, false, sizeof(spSet));
    int i,j;

    for(i=0;i<MAX;i++) {
        shortest_path[i]=INT_MAX;
        spSet[i]=false;
        graph[i].clear();
    }

    for(i=1;i<=MAX_NODES;i++) {
        for(j=1;j<=6;j++){
            if((i+j)>100) {
                break;
            }
            graph[i].push_back((i+j));
            /*
            cell temp;
            temp.cost=1;
            temp.dest=(i+j);
            graph[i].push_back(temp);
            */
        }
    }
}

void printGraph()
{
    int i,j;
    for(i=1;i<=100;i++) {
        printf("%d-> ",i);
        for(j=0;j<graph[i].size();j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int minDistance()
{
    int i,min=INT_MAX,node=-1;
    for(i=1;i<=100;i++) {
        if( !spSet[i] && min > shortest_path[i] ) {
            min=shortest_path[i];
            node=i;
        }
    }
    //printf("min=%d\n",min);
    return node;
}

int Dijksktra(int src)
{
    shortest_path[src]=0;

    int i,j;

    for(i=1;i<=100;i++) {
        //int u=minDistance(spSet, shortest_path);
        int u=minDistance();
                    // find the shortest path node
                    // which is not yet traversed
        spSet[u]=true;

        int node;
        for(j=0;j<graph[u].size();j++) {
            node=graph[u][j];
            if( !spSet[node] && shortest_path[u]!=INT_MAX && shortest_path[u]+1 < shortest_path[node] ) {
                shortest_path[node] = shortest_path[u]+1;
            }
        }

    }
    return 0;
}

int main()
{
    int i,j,t,n_laders,n_snakes, x, y, start;
    scanf("%d",&t);
    while(t--) {
        initialise();
        start=1;


        scanf("%d",&n_laders);
        for(i=0;i<n_laders;i++) {
            scanf("%d %d",&x,&y);
            //graph[x].push_back(y);
            /*
            cell temp;
            temp.cost=0;
            temp.dest=y;
            graph[x].push_back(temp);
            */
            graph[x].clear();
            for(j=1;j<=100;j++) {
                int k;
                for(k=0;k<graph[j].size();k++) {
                    if(graph[j][k]==x) {
                        graph[j][k]=y;
                    }
                }
            }
            graph[x].push_back(y);
            if(x==1) {
                start=y;
            }
        }
        scanf("%d",&n_snakes);
        for(i=0;i<n_snakes;i++) {
            scanf("%d %d",&x,&y);
            /*
            cell temp;
            temp.cost=0;
            temp.dest=y;
            graph[x].push_back(temp);
            */
            graph[x].clear();
            for(j=1;j<=100;j++) {
                int k;
                for(k=0;k<graph[j].size();k++) {
                    if(graph[j][k]==x) {
                        graph[j][k]=y;
                    }
                }
            }
            graph[x].push_back(y);
            if(x==1) {
                start=y;
            }
        }

        Dijksktra(start);

        if(shortest_path[100]==INT_MAX) {
            printf("-1\n");
        } else {
            printf("%d\n",shortest_path[100]);
        }

    }

    return 0;
}

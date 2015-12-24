#include<stdio.h>
#include<limits.h>
#define V 9
int minDistance(int dist[V], bool sptSet[V])
{
    int i,min=INT_MAX,minPos;
    for(i=0;i<V;i++)
    {
        if(dist[i]<min && !sptSet[i])
        {
            min=dist[i];
            minPos=i;
        }
    }
    return minPos;
}
int printResult(int dist[V],int n)
{
    printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
   {
       printf("%d \t\t %d\n", i, dist[i]);
   }
    return 0;
}

int dijksktra(int graph[V][V], int source)
{
    int dist[V];
    bool sptSet[V];
    int i;
    for(i=0;i<V;i++)
    {
        dist[i]=INT_MAX; // setting the distance to be maximum value of int (or Infinity)s
        sptSet[i]=false; // all nodes are not travelled
    }
    dist[source]=0; // setting the source node's distance = 0
    for(i=0;i<V;i++)
    {
        int u=minDistance(dist,sptSet); // To get the node with minimum distance which is unvisited
        sptSet[u]=true;
        for(int v=0;v<V;v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v]; // setting the distance of a node from a node which is already visited
            }
        }
    }
    printResult(dist,0);
    return 0;
}
int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    // perform dijksktra's SP Algo
    dijksktra(graph,0);  // sending the base node (0)
    return 0;
}

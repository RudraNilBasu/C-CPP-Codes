//http://www.spoj.com/problems/BUGLIFE/
/*
Solution of BUGLIFE Problem from SPOJ (http://www.spoj.com/problems/BUGLIFE/)
Main algorithm - BFS with implementation of checking Bipartite graph (http://www.geeksforgeeks.org/bipartite-graph/)
Done by :- Rudra Nil Basu
*/

#include<stdio.h>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;


int gender[2001]; // to mark the gender of a bug. Gender of bug 'x' is gender[x]
int flag=0;     // to check whether the answer is correct or not. if flag==1 then ans is wrong, else correct

int isBipartite(int src,vector<int> (&g)[2001])
{
    gender[src]=1;//marking source vertex as 1
    queue<int>q;
    q.push(src);
    while(!q.empty()) // BFS traversal
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            if(gender[g[u][i]]==-1) // ignoring if the bug is alreay visited
            {
                gender[g[u][i]]=1-gender[u]; // marking the gender[] of the Bug
                q.push(g[u][i]);
            }
            else if(gender[g[u][i]]!=-1 && gender[g[u][i]]==gender[u])
            {                   // cycle present and both the nodes have same gender
                flag=1;         // flag is set to 1 meaning that the answer is wrong
                return 1;
            }
        }
    }
    return 0; // if successfully executed
}

int main()
{
    int t;//number of scenarios
    int i,u,v,k=0,bug;
    long int intr;// intr = no of interactions
    scanf("%d",&t);
    while(t--) // running the scenarios
    {
        k++;// scenario number
        flag=0;
        for(i=0;i<2001;i++)
        {
            gender[i]=-1; // resetting
        }
        vector<int>g[2001];
        scanf("%d",&bug);//input the no of bugs
        scanf("%ld",&intr);//input the no of interactions
        while(intr--) // creating the graph in the vector g[] as adjacency list
        {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(i=1;i<=bug;i++)
        {
            if(gender[i]==-1)
            {
                isBipartite(i,g);
            }
        }
        printf("Scenario #%d:\n",k);
        if(flag)
        {
            printf("Suspicious bugs found!\n");
        }
        else
        {
            printf("No suspicious bugs found!\n");
        }
    }
    return 0;
}

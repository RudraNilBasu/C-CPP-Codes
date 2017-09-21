#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

typedef struct edges {
        int u;
        int v;
}edges;

int main()
{
        int n, i, j;
        scanf("%d", &n);
        vector <int> g[n+1];

        int u, v;
        for (i = 1; i <= n-1; i++) {
                scanf("%d %d", &u, &v);
                g[u].push_back(v);
                g[v].push_back(u);

                edges temp;
                temp.u = u;
                temp.v = v;
        }

        int colors[n+1];
        for (i = 1; i <= n; i++)
                colors[i] = -1;
        colors[1] = 1;
        queue<int> q;
        q.push(1);

        long long int nodeCount[2];
        nodeCount[0] = 0;
        nodeCount[1] = 0;

        while (!q.empty()) {
                int node = q.front();
                nodeCount[ colors[node]]++;
                q.pop();
                for (i = 0; i < g[node].size(); i++) {
                        if ( colors[ g[node][i] ] == -1 ) {
                                colors[ g[node][i] ] = 1 - colors[node];
                                q.push(g[node][i]);
                        }
                }
        }

        long long int count = (nodeCount[0] * nodeCount[1]) - (n - 1);
        cout << count << endl;
}

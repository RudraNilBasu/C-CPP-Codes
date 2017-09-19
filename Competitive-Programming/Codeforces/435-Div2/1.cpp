#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

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

        while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (i = 0; i < g[node].size(); i++) {
                        if ( colors[ g[node][i] ] == -1 ) {
                                colors[ g[node][i] ] = 1 - colors[node];
                                q.push(g[node][i]);
                        }
                }
        }

        int count = 0;
        for (i = 1; i <= n; i++) {
                if (colors[i] == 0)
                        continue;
                for (j = 1; j <= n; j++) {
                        if (j == i)
                                continue;
                        if (colors[i] == colors[j])
                                continue;
                        if ( find(g[i].begin(), g[i].end(), j) != g[i].end() )
                                continue;
                        count++;
                        //g[i].push_back(j);
                        //printf("%d (%d) %d (%d)\n", i, colors[i], j, colors[j]);
                }
        }
        //count /= 2;
        printf("%d\n", count);
}

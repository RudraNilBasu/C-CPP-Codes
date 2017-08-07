#include <stdio.h>
#include <vector>

using namespace std;

int dfs(int node, vector<int>* g, int* traversed)
{
        int i;
        for (i = 0; i < g[node].size(); i++) {
                if (traversed[ g[node][i] ] == -1) {
                        traversed[ g[node][i]] = node;
                        dfs(g[node][i], g, traversed);
                }
        }
        return 0;
}

int main()
{
        int n, m, i;
        scanf("%d %d", &n, &m);
        vector<int> g[n + 1];
        int traversed[n + 1];

        for (i = 1; i <= m; i++) {
                int x, y;
                scanf("%d %d", &x, &y);
                g[x].push_back(y);
                g[y].push_back(x);
        }

        for (i = 1; i <= n; i++) {
                traversed[i] = -1;
        }
        traversed[1] = 0;
        dfs(1, g, traversed);
        bool tree = true;
        for (i = 1; i <= n; i++) {
                if (traversed[i] == -1) {
                        tree = false;
                        break;
                }
        }
        if (tree && (m == n - 1))
                printf("YES\n");
        else
                printf("NO\n");
}

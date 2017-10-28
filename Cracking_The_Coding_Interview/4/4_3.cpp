#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

typedef struct node {
        int value;
        int depth;
}node;

void storeDepth(int root_value, std::vector<int>g[], int n)
{
        bool visited[n + 1];
        memset(visited, false, sizeof visited);
        std::queue<node> q;
        std::vector<int> list[n + 1];

        node root_node;
        root_node.value = root_value;
        root_node.depth = 0;
        
        q.push(root_node);
        visited[root_node.value] = true;
        //list[root_node.depth].push_back(root_node.value);

        while (!q.empty()) {
                node u = q.front();
                q.pop();
                for (int i = 0; i < g[u.value].size(); i++) {
                        if (!visited[ g[u.value][i] ]) {
                                node _node;
                                _node.value = g[u.value][i];
                                _node.depth = u.depth + 1;

                                q.push(_node);
                                visited[ _node.value ] = true;
                        }
                }
                //std::cout << u << std::endl;
                list[u.depth].push_back(u.value);
        }
        for (int i = 0; i < n + 1; i++) {
                if (list[i].size() == 0)
                        break;
                std::cout << "Depth: " << i << " : ";
                for (int j = 0; j < list[i].size(); j++) {
                        std::cout << list[i][j] << " ";
                }
                std::cout << std::endl;
        }
}

int main()
{
        int n, m;
        std::cin >> n >> m;
        std::vector<int> g[n + 1];
        int u, v;
        for (int i = 0; i < m; i++) {
                std::cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }

        std::cout << "Root: ";
        int root;
        std::cin >> root;

        storeDepth(root, g, n);

        //std::vector<int> lists[n + 1];
        return 0;
}

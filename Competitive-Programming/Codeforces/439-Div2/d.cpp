#include <iostream>
#include <cstdio>
#include <vector>

#define ll long long int
#define MOD 1000000007

int count_edges(std::vector<int> *g, int i, int parent)
{
        std::cout << i <<std::endl;
        if (g[i].size() == 0 || i <= parent)
                return 0;

        ll paths_from_here = 0;
        for (int j = 0; j < g[i].size(); j++) {
                std::cout << "Calc for " << g[i][j] << std::endl;
                paths_from_here = (paths_from_here % MOD + (1 + count_edges(g, g[i][j], i) % MOD) % MOD) % MOD;
        }
        return paths_from_here;
}

int main()
{
        std::cout << "LOL\n";
#ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
#endif
        std::cout << "LOL\n";
        int i;
        ll n;
        std::cin >> n;
        std::vector<int> g[n + 1];

        for (i = 1; i <= n; i++) {
                if ((i * 2) <= n) {
                        g[i].push_back(i * 2);
                }
                if (((i * 2) + 1) <= n) {
                        g[i].push_back((i * 2) + 1);
                }
        }

        int m, x, y;
        std::cin >> m;
        for (i = 1; i <= m; i++) {
                std::cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }

        std::cout << count_edges(g, 1, -1) << std::endl;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;


void printList(vector<int> g)
{
        int i;
        cout << "current list: \n";
        for (i = 0; i < g.size(); i++)
                cout << g[i] << " ";
        cout << endl;
}

int main()
{
        vector<int> g;
        int n, i;
        cin >> n;
        int temp;
        for (i = 0; i < (2 * n); i++) {
                cin >> temp;
                g.push_back(temp);
        }

        sort(g.begin(), g.end());
        int s1, s2; /* Indices of single users */
        int min_sum = INT_MAX;
        for (s1 = 0; s1 < (2 * n) - 1; s1++) {
                for (s2 = s1 + 1; s2 < 2 * n; s2++) {
                        vector<int> pairs;
                        for (i = 0; i < 2 * n; i++) {
                                if (i == s1 || i == s2)
                                        continue;
                                pairs.push_back(g[i]);
                        }
                        int sum = 0;
                        for (i = 0; i < pairs.size(); i += 2)
                                sum += abs(pairs[i + 1] - pairs[i]);
                        min_sum = min(min_sum, sum);
                }
        }
        cout << min_sum << endl;
        return 0;
}

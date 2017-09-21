#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

typedef struct node {
        int fIndex;
        int lIndex;
        int diff;
}node;

node findMin(vector<int> g)
{
        int i;
        node temp;
        temp.diff = INT_MAX;
        for (i = 0; i < g.size(); i++) {
                int ld = abs(g[i+1] - g[i]);
                if (ld < temp.diff) {
                        temp.fIndex = i;
                        temp.lIndex = i + 1;
                        temp.diff = ld;
                }
        }
        return temp;
}

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
        //int a[2*n];
        for (i = 0; i < (2 * n); i++) {
                cin >> temp;
                g.push_back(temp);
        }

        sort(g.begin(), g.end());
        int count = 0;
        long long int sum = 0;
        while (count < (n- 1)) {
                node l = findMin(g);
                sum += l.diff;
                //cout << "Deleting: " << g[l.fIndex] << " , " << g[l.lIndex] << " : " << l.diff << endl;
                g.erase(g.begin() + l.lIndex);
                g.erase(g.begin() + l.fIndex);
                count++;
        }
        cout << sum << endl;
        return 0;
}

#include <stdio.h>
#include <iostream>
#include <math.h>

#define MOD 998244353

using namespace std;

int main()
{
        int a, b, c;
        cin >> a >> b >> c;

        int _a = a, _b = b, _c = c;
        int i, total_nodes = 0;

        for (i = 1; i <= a; i++) {
                if (b > 0) {
                        total_nodes += b;
                        b--;
                }

                if (c > 0) {
                        total_nodes += c;
                        c--;
                }
        }

        b = _b, c = _c;

        for (i = 1; i <= c; i++) {
                if (b > 0) {
                        total_nodes += b;
                        b--;
                }
        }
        cout << (int)pow(2, total_nodes) % MOD << endl;
        return 0;
}

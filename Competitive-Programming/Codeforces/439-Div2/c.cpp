#include <stdio.h>
#include <iostream>
#include <math.h>

#define MOD 998244353
#define ll long long int

using namespace std;

int fact[5001];
int nCr[5001][5001];
int calc_bridges(int islands_a, int islands_b)
{
        int i;
        int res = 0;
        for (i = 0; i <= islands_a && i <= islands_b; i++) {
                int ans = fact[i];
                ans = (1LL * ans * nCr[islands_a][i]) % MOD;
                ans = (1LL * ans * nCr[islands_b][i]) % MOD;

                res = (res + ans) % MOD;
        }
        return res;
}

int main()
{
#ifdef LOCAL
        // use it via g++ c.cpp -DLOCAL
        freopen("inp.txt", "r", stdin);
#endif
        int a, b, c;
        cin >> a >> b >> c;

        nCr[0][0] = 1;
        for (int i = 1; i <= 5000; i++) {
                nCr[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                        nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
                }
        }
        fact[0] = 1;
        for (int i = 1; i <= 5000; i++)
                fact[i] = (1LL * fact[i - 1] * i) % MOD;

        int ans1 = calc_bridges(a, b);
        int ans2 = calc_bridges(a, c);
        int ans3 = calc_bridges(b, c);

        int ans = (((1LL * ans1 * ans2) % MOD) * ans3) % MOD;

        cout << ans << endl;

        return 0;
}

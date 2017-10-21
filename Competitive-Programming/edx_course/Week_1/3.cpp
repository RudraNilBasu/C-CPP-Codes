#include <iostream>
#include <string.h>

#define ll long long int

int a, b, c;

int dp[100001];

int f(int n)
{
        if (dp[n] != -1)
                return dp[n];
        if (n == 0)
                return dp[n] = a;
        if (n == 1)
                return dp[n] = b;
        if (n == 2)
                return dp[n] = c;
        return dp[n] = f(n - 1) + f(n - 2) - f(n - 3);
}

int main()
{
#ifdef JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
#endif

        int n;
        memset(dp, -1, sizeof(dp));
        std::cin >> a >> b >> c >> n;
        std::cout << f(n) << std::endl;
}

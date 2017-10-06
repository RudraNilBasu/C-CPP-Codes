#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include<bits/stdc++.h>

#define MOD 1e9 + 7
#define NMAX 155

int n;
int a[NMAX];

int dp[NMAX][NMAX][NMAX];

/*
int min(int x, int y)
{
        return (x > y) ? y : x;
}
*/

inline int no_of_arrays(int pos, int curr_pos_value, int next_pos_extra_values)
{
        int pos_value = curr_pos_value;
        int next_pos_value = a[pos + 1] + next_pos_extra_values;
        int decrease_amt = std::min(pos_value, next_pos_value);

        if (dp[pos][pos_value][next_pos_value] != -1)
                return dp[pos][pos_value][next_pos_value];
        if (pos >= n && !decrease_amt)
                return dp[pos][pos_value][next_pos_value] = 1;

        int ans = 0;
        int i;

        for (i = 0; i <= decrease_amt; i++) {
                ans += no_of_arrays(pos + 1, next_pos_value - i, i);
                if (ans >= MOD)
                        ans -= MOD;
        }
        dp[pos][pos_value][next_pos_value] = ans;
}

int main()
{
        int t;
        scanf("%d", &t);
        while (t--) {
                scanf("%d", &n);
                memset(a, 0, sizeof a);
                memset(dp, -1, sizeof dp);
                for (int i = 0; i < n; i++)
                        scanf("%d", (a + i));
                memset(dp, -1, sizeof dp);
                printf("%lld\n", no_of_arrays(0, a[0], 0));
        }
        return 0;
}

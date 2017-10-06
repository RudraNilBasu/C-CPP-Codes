#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int min2(int, int);
int min3(int, int, int);
int min4(int, int, int, int);

/*
char a[3000], b[3000];
char a_size, b_size;

int memo[3001][3001];
*/

int min4(int a, int b, int c, int d)
{
        return min2(min3(a, b, c), d);
}

int min3(int a, int b, int c)
{
        return min2( min2(a, b), c );
}

int min2(int a, int b)
{
        return (a > b) ? b : a;
}

/*
int opr(int a_start, int b_start)
{
        if (a_start < 0) {
                //printf("Returning: %d\n",((b_start < 0) ? 0 : b_start));
                return b_start + 1;//(b_start < 0) ? 0 : b_start;
        }
        if (b_start < 0) {
                //printf("Returning: %d\n",((a_start < 0) ? 0 : a_start));
                return a_start + 1;//(a_start < 0) ? 0 : a_start;
        }

        if (memo[a_start][b_start] != -1)
                return memo[a_start][b_start];

        if (a[a_start] == b[b_start]) {
                return memo[a_start][b_start] = opr(a_start - 1, b_start - 1);
        } else {
                return memo[a_start][b_start] = 1 + min3(
                                opr(a_start - 1, b_start - 1),
                                opr(a_start, b_start - 1),
                                opr(a_start - 1, b_start)
                                );
        }
}
*/

/*
int top_down()
{
        int i, j;
        int dp[2001][2001];
        for (i = 0; i <= a_size; i++) {
                for (j = 0; j <= b_size; i++) {
                        if (i == 0)
                                dp[i][j] = j;
                        else if (j == 0)
                                dp[i][j] = i;
                        else if (a[i - 1] == b[j - 1])
                                dp[i][j] = dp[i - 1][j - 1];
                        else
                                dp[i][j] = 1 + min3(
                                                dp[i - 1][j],
                                                dp[i][j - 1],
                                                dp[i - 1][j - 1]
                                                );
                }
        }
        return dp[a_size][b_size];
}
*/
/*
int opr(int a_start, int b_start)
{
        // base case
        if (a_start >= a_size)
                return (b_size - b_start);
        if (b_start >= b_size)
                return (a_size - a_start);
        if (memo[a_start][b_start] != -1)
                return memo[a_start][b_start];
        // other case
        // 1. Delete a[a_start]
        // 2. Insert before a[a_start]
        // 3. Replace a[a_start] with something
        if (a[a_start] == b[b_start]) {
                return memo[a_start][b_start] = min4(
                                opr(a_start + 1, b_start) + 1,
                                opr(a_start, b_start + 1) + 1,
                                opr(a_start + 1, b_start + 1),
                                opr(a_start + 1, b_start + 1) + 1
                                );
        } else {
                return memo[a_start][b_start] = min3(
                                opr(a_start + 1, b_start) + 1,
                                opr(a_start, b_start + 1) + 1,
                                opr(a_start + 1, b_start + 1) + 1
                                );
        }
}
*/
/*
int edist(int m, int n)
{
        if (m == 0)
                return memo[m][n] = n;
        if (n == 0)
                return memo[m][n] = m;

        if (a[m - 1] == b[n - 1])
                return memo[m][n] = edist(m - 1, n - 1);

        return memo[m][n] = 1 + min3(
                        edist(m, n - 1),
                        edist(m - 1, n),
                        edist(m - 1, n - 1)
                        );
}
*/

int edist_td()
{
        char a[3000], b[3000];
        scanf("%s", a);
        scanf("%s", b);
        int m = strlen(a);
        int n = strlen(b);
        int dp[3000][300];
        memset(dp,0,sizeof(dp[0][0])*(m+1)*(n+1));
        int i,j;

        for (i = 0; i <= m; i++)
                dp[i][0] = i;
        for (j = 0; j <= n; j++)
                dp[0][j] = j;
        for (i = 1; i <= m; i++) {
                for (j = 1; j <= n; j++) {
                        if (a[i - 1] ==b[j - 1]) {
                                dp[i][j] = dp[i - 1][j - 1];
                        } else {
                                dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
                        }
                }
        }
        printf("%d\n", dp[m][n]);
        /*
        for (i = 0; i <= m; i++) {
                for (j = 0; j <= n; j++) {
                        if (i == 0) {
                                dp[i][j] = j;
                        } else if (j == 0) {
                                dp[i][j] = i;
                        } else if (a[i - 1] == b[j - 1]) {
                                dp[i][j] = dp[i - 1][j - 1];
                        } else {
                                dp[i][j] = 1 + min3(
                                                dp[i][j - 1],
                                                dp[i - 1][j],
                                                dp[i - 1][j - 1]
                                                );
                        }
                }
        }
        return dp[m][n];
        */
}

/*
int init()
{
        //memset(memo, -1, sizeof(memo));
        int i, j;
        for (i = 0; i < 3001; i++)
                for (j = 0; j < 3001; j++)
                        memo[i][j] = -1;
}
*/

int main()
{
        int t;
        scanf("%d", &t);
        while (t--) {
                edist_td();
                //init();
                //scanf("%s %s", a, b);
                //a_size = strlen(a);
                //b_size = strlen(b);
                //printf("%d\n", edist_td(a_size, b_size));
                //printf("%d\n", top_down());
                //printf("%d\n", opr(a_size - 1, b_size - 1));
                //top_down();
                //printf("%d\n", opr(0, 0));
        }
        return 0;
}

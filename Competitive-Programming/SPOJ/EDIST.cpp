#include <stdio.h>
#include <string.h>

using namespace std;

int min2(int, int);
int min3(int, int, int);
int min4(int, int, int, int);

char a[2001], b[2001];
char a_size, b_size;

int memo[3001][3001];

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

int init()
{
        //memset(memo, -1, sizeof(memo));
        int i, j;
        for (i = 0; i < 3001; i++)
                for (j = 0; j < 3001; j++)
                        memo[i][j] = -1;
}

int main()
{
        int t;
        scanf("%d", &t);
        while (t--) {
                init();
                scanf("%s %s", a, b);
                a_size = strlen(a);
                b_size = strlen(b);
                printf("%d\n", opr(0, 0));
        }
        return 0;
}

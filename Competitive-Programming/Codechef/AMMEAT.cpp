#include <stdio.h>
#include <algorithm>
#include <climits>

#define ull unsigned long long int
#define MAX ULLONG_MAX

using namespace std;

int main()
{
        int t, n, i;
        scanf("%d", &t);
        ull m, sum;
        while (t--) {
                scanf("%d %llu", &n, &m);
                ull p[n];
                for (i = 0; i < n; i++) {
                        scanf("%llu", (p + i));
                }
                sort(p, p + n);
                sum = 0;
                int c = 0;
                bool found = false;
                for (i = n - 1; i >= 0; i--) {
                        sum = ((sum % MAX ) + (p[i] % MAX) % MAX);
                        c++;
                        if (sum >= m) {
                                found = true;
                                break;
                        }
                }
                if (!found) {
                        printf("-1\n");
                } else {
                        printf("%d\n", c);
                }
        }
        return 0;
}

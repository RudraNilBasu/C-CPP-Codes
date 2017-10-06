#include <stdio.h>
#include <map>

using namespace std;

int main()
{
        int n;
        scanf("%d", &n);

        map<int, bool> occ;
        int i, j, x, cnt = 0;

        for (i = 1; i <= (2 * n); i++) {
                scanf("%d", &x);
                occ[ x ] = true;
        }

        for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                        x = (i ^ j);
                        if (occ[x])
                                cnt++;
                }
        }
        if (cnt & 1)
                printf("Koyomi\n");
        else
                printf("Karen\n");
        return 0;
}

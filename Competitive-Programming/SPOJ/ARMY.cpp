#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int t, ng, nm, i;
        scanf("%d", &t);
        while (t--) {
                scanf("%d %d", &ng, &nm);
                int g[ng], m[nm];
                int gmax = -1, mmax = -1;
                for (i = 0; i < ng; i++) {
                        scanf("%d", (g + i));
                        if (g[i] > gmax) {
                                gmax = g[i];
                        }
                }
                for (i = 0; i < nm; i++) {
                        scanf("%d", (m + i));
                        if (m[i] > mmax) {
                                mmax = m[i];
                        }
                }
                int winner = 0;
                if (mmax > gmax) {
                        winner = 2;
                } else {
                        winner = 1;
                }
                /*
                sort(g, g + ng);
                sort(m, m + nm);
                // j = godzilla
                // k = mechagodzilla
                int j = 0, k = 0, winner = 0;
                while ((j < ng) && (k < nm)) {
                        if (g[j] < m[k]) {
                                j++;
                        } else if (m[k] <= g[j]) {
                                k++;
                        }
                        if (j == ng) {
                                winner = 2;
                                break;
                        }
                        if (k == nm) {
                                winner = 1;
                                break;
                        }
                }
                */
                if (winner == 1) {
                        printf("Godzilla\n");
                } else if (winner == 2) {
                        printf("MechaGodzilla\n");
                } else {
                        printf("MechaGodzilla\n");
                }
        }
        return 0;
}

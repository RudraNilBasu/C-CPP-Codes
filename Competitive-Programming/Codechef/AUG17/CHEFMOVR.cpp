#include <stdio.h>

using namespace std;

int main()
{
        int t, n, d, i;
        scanf("%d", &t);
        while (t--) {
                scanf("%d %d", &n, &d);
                int a[n];
                int sum = 0;
                for (i = 0; i < n; i++) {
                        scanf("%d", (a + i));
                        sum += a[i];
                }
                if (sum % n != 0) {
                        printf("-1\n");
                        continue;
                }

                sum /= n;

                int leftStep = 0, rightStep = 0;
                for (i = 0; i < n; i++) {
                        // [0, i) is balanced
                        if (a[i] == sum) {
                                continue;
                        } else if (a[i] > sum) {
                                // transfer extra numbers to i + D
                                if ((i + D) >= n) {
                                        leftStep = -1;
                                        break;
                                }
                                int diff = a[i] - sum;
                        }
                }
        }
        return 0;
}

#include <stdio.h>

using namespace std;

int main()
{
        int t, n, d, i;
        scanf("%d", &t);
        while (t--) {
                scanf("%d %d", &n, &d);
                int a[n];
                int orig[n];
                int sum = 0;
                for (i = 0; i < n; i++) {
                        scanf("%d", (a + i));
                        orig[i] = a[i];
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
                                if ((i + d) >= n) {
                                        leftStep = -1;
                                        break;
                                }
                                int diff = a[i] - sum;
                                a[i+d] += diff;
                                leftStep += diff;
                                a[i] = sum;
                        } else if (a[i] < sum) {
                                if ((i + d) >= n) {
                                        leftStep = -1;
                                        break;
                                }
                                int diff = sum - a[i];
                                if (a[i + d] < diff) {
                                        leftStep = -1;
                                        break;
                                }
                                a[i+d] -= diff;
                                leftStep += diff;
                                a[i] = sum;
                        }
                }
                //printf("%d\n", leftStep);
                for (i = 0; i < n; i++)
                        a[i] = orig[i];

                for (i = n - 1; i >= 0; i--) {
                        // (i, n] is balanced
                        if (a[i] == sum) {
                                continue;
                        } else if (a[i] > sum) {
                                // transfer extra numbers to i - D
                                if ((i - d) < 0) {
                                        rightStep = -1;
                                        break;
                                }
                                int diff = a[i] - sum;
                                a[i-d] += diff;
                                rightStep += diff;
                                a[i] = sum;
                        } else if (a[i] < sum) {
                                int diff = sum - a[i];
                                if ((i - d) < 0) {
                                        rightStep = -1;
                                        break;
                                }
                                if (a[i - d] < diff) {
                                        rightStep = -1;
                                        break;
                                }
                                a[i-d] -= diff;
                                rightStep += diff;
                        }
                }
                if (leftStep == -1 && rightStep == -1) {
                        printf("-1\n");
                        continue;
                } else if (leftStep == -1) {
                        printf("%d\n", rightStep);
                } else if (rightStep == -1) {
                        printf("%d\n", leftStep);
                } else {
                        printf("%d\n", ((leftStep < rightStep) ? leftStep : rightStep));
                }
        }
        return 0;
}

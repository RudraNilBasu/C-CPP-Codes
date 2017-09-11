#include <stdio.h>
#include <limits.h>
#include <vector>
#include <stdlib.h>

#define ll long long int
#define MAX LLONG_MAX
using namespace std;

int main()
{
        int t, n, d, i, j;
        scanf("%d", &t);
        while (t--) {
                scanf("%d %d", &n, &d);
                ll a[n];
                ll orig[n];
                ll sum = 0;
                for (i = 0; i < n; i++) {
                        scanf("%lld", (a + i));
                        orig[i] = a[i];
                        sum = (sum % MAX + a[i] % MAX) % MAX;
                }
                if (sum % n != 0) {
                        printf("-1\n");
                        continue;
                }

                sum /= n;

                vector<ll> g[d];
                ll sub_sum;
                int flag = 0;
                for (i = 0; i < d; i++) {
                        j = i;
                        sub_sum = 0;
                        while (j < n) {
                                g[i].push_back(a[j]);
                                sub_sum = (sub_sum % MAX + a[j] % MAX) % MAX;
                                j += d;
                        }
                        if ((sub_sum % g[i].size() != 0) || (sub_sum/g[i].size() != sum)) {
                                flag = 1;
                                break;
                        }
                }
                if (flag) {
                        printf("-1\n");
                        continue;
                }

                ll minStep = 0;
                for (i = 0; i < d; i++) {
                        for (j = 0; j < g[i].size(); j++) {
                                if (g[i][j] == sum) {
                                        continue;
                                } else if (g[i][j] < sum) {
                                        // find right index with g[i][j] > sum
                                        int right = j + 1;
                                        while (right < g[i].size()) {
                                                if (g[i][right] > sum) {
                                                        break;
                                                }
                                                right++;
                                        }
                                        int left = j - 1;
                                        while (left >= 0) {
                                                if (g[i][left] > sum) {
                                                        break;
                                                }
                                                left--;
                                        }
                                        int fetch_index;
                                        if (left < 0) {
                                                // left is invalid, use right
                                                fetch_index = right;
                                        } else if (right >= g[i].size()) {
                                                fetch_index = left;
                                        } else {
                                                if ((right - j) < (left - j)) {
                                                        fetch_index = right;
                                                } else {
                                                        fetch_index = left;
                                                }
                                        }
                                        // send from index
                                        ll diff_index = g[i][fetch_index] - sum;
                                        ll diff_curr = sum - g[i][j];
                                        if (diff_index >= diff_curr) {
                                                g[i][j] += diff_curr;
                                                g[i][fetch_index] -= diff_curr;
                                                minStep += (diff_curr * abs(fetch_index - j));
                                        } else {
                                                g[i][j] += diff_index;
                                                g[i][fetch_index] -= diff_index;
                                                minStep += (diff_index * abs(fetch_index - j));
                                                j--;
                                        }
                                }
                        }
                }
                printf("%lld\n", minStep);
                /*
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
        */
        }
        return 0;
}

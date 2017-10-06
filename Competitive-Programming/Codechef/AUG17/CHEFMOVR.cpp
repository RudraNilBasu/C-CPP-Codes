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
                                        int other_index;
                                        if (left < 0) {
                                                // left is invalid, use right
                                                fetch_index = right;
                                                other_index = left;
                                        } else if (right >= g[i].size()) {
                                                fetch_index = left;
                                                other_index = right;
                                        } else {
                                                if ((right - j) < (left - j)) {
                                                        fetch_index = right;
                                                        other_index = left;
                                                } else {
                                                        fetch_index = left;
                                                        other_index = right;
                                                }
                                        }
                                        bool complete = true;
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
                                                if (other_index >= 0 && other_index < n) {
                                                        diff_index = g[i][other_index] - sum;
                                                        diff_curr = sum - g[i][j];
                                                        if (diff_index >= diff_curr) {
                                                                g[i][j] += diff_curr;
                                                                g[i][other_index] -= diff_curr;
                                                                minStep += (diff_curr * abs(other_index - j));
                                                        } else {
                                                                g[i][j] += diff_index;
                                                                g[i][other_index] -= diff_index;
                                                                minStep += (diff_index * abs(other_index - j));
                                                                //j--;
                                                                complete = false;
                                                        }
                                                } else {
                                                        //j--;
                                                        complete = false;
                                                }
                                        }
                                        if (!complete) {
                                                j--;
                                        }
                                }
                        }
                }
                printf("%lld\n", minStep);
        }
        return 0;
}

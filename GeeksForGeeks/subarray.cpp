//http://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int t, n, x;
        scanf("%d", &t);
        while (t--) {
                scanf("%d %d", &n, &x);
                int a[n];
                int i;
                for (i = 0; i < n; i++)
                        scanf("%d", a+i);
                int start = 0, end = 0, sum = a[0], flag = 0;
                while (start < n && end < n) {
                        if (sum == x) {
                                flag = 1;
                                break;
                        }
                        if (sum > x) {
                                sum -= a[start++];
                        } else if (sum < x) {
                                //end++;
                                sum += a[++end];
                        }
                }
                if (!flag) {
                        printf("-1\n");
                } else {
                        printf("%d %d\n", (start + 1), (end + 1));
                }
        }
        return 0;
}

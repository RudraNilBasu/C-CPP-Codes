#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int t, n, x, i, flag;
        scanf("%d",&t);
        while (t--) {
                flag = 0;
                scanf("%d %d",&n, &x);
                int a[n];
                for (i = 0; i < n; i++) {
                        scanf("%d",(a+i));
                }
                sort(a, a+n);
                for (i = 0; i < n; i++) {
                        if (binary_search(a, a + n, (x - a[i]))) {
                                flag = 1;
                                printf("Yes\n");
                                break;
                        }
                }
                if (flag == 0) {
                        printf("No\n");
                }
        }
        return 0;
}

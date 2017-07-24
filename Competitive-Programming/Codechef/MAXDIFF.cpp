#include <stdio.h>
#include <algorithm>

#define ll long long int

using namespace std;

ll calc_diff(ll w[], int n, int k)
{
        int i;
        ll sum1 = 0, sum2 = 0, diff;
        for(i = 0;i < k;i++) {
                sum1 += w[i];
        }
        for(i = k;i < n;i++) {
                sum2 += w[i];
        }
        return abs(sum2 - sum1);
}

int main()
{
        int t,k,n;
        scanf("%d",&t);
        while(t--) {
                scanf("%d %d", &n, &k);
                ll w[n];
                int i;
                for(i = 0;i < n;i++) {
                        scanf("%lld",(w+i));
                }
                sort(w, w+n);
                /*
                ll sum1 = 0, sum2 = 0, diff;
                for(i = 0;i < k;i++) {
                        sum1 += w[i];
                }
                for(i = k;i < n;i++) {
                        sum2 += w[i];
                }
                */
                ll diff1 = calc_diff(w, n, k);
                reverse(w, w+n);
                ll diff2 = calc_diff(w, n, k);

                printf("%lld\n", max(diff1, diff2));
        }
        return 0;
}

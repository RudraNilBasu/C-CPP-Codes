#include<stdio.h>
#include<algorithm>
#define ll long long int
using namespace std;
int main()
{
    int t,n,i;
    ll sum;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        ll h[n];
        int s=1,p=0;
        ll max=-1;
        sum=0;
        for(i=0;i<n;i++) {
            scanf("%lld",&h[i]);
            sum+=h[i];
        }
        sort(h,h+n);
        max=h[n-1];
        for(i=0;i<n;i++) {
            sum-=h[i];
            s++;
            if(max<(s*sum)) {
                max=s*sum;
            }
        }
        printf("%lld\n",max);
    }
    return 0;
}

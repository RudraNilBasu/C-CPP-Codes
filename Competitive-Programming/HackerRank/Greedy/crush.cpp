#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long int
using namespace std;

ll arr[10000002];
int main() {
    int n,m,a,b,i;
    scanf("%d %d",&n, &m);
    ll k, max;
    max=0;
    memset(arr,0,sizeof(arr));
    while(m--) {
        scanf("%d %d %lld",&a,&b,&k);
        arr[a]+=k;
        if(b+1<=n) {
            arr[b+1]-=k;
        }
    }
    ll x=0;
    for(i=1;i<=n;i++) {
        x=x+arr[i];
        if(x>max) {
            max=x;
        }
    }
    printf("%lld\n",max);
    return 0;
}

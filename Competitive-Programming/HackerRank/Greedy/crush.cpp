#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

#define ll long long int
using namespace std;

ll arr[10000001];
int main() {
    int n,m,a,b,i;
    scanf("%d %d",&n, &m);
    ll k, max, max_in_range;
    max=0;
    max_in_range=0;
    memset(arr,0,sizeof(arr));
    while(m--) {
        scanf("%d %d %lld",&a,&b,&k);
        for(i=a-1;i<b;i++) {
            arr[i]+=k;
        }
    }
    for(i=0;i<n;i++) {
        if(max<arr[i]) {
            max=arr[i];
        }
    }
    printf("%lld\n",max);
    return 0;
}

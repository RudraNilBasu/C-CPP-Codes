#include<stdio.h>
#define ll long long int
using namespace std;
int main()
{
    int n,i;
    ll k;
    scanf("%d %lld",&n,&k);
    if(k>=(n-1)) {
        for(i=n;i>=1;i--) {
            printf("%d ",i);
        }
        printf("\n");
        return 0;
    }
    int a[n],loc[n];
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
        loc[(a[i]-1)]=i+1;
    }
    ll count=k;
    for(i=0;i<n && count;i++) {
        if(a[i]!=(n-i)) {
            a[ loc[n-i-1] -1 ] = a[i];
            loc[a[i]-1]=loc[n-i-1];

            a[i]=n-i;
            loc[n-i-1]=i+1;

            count--;
        }
    }
    for(i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    //printf("\n");
    return 0;
}

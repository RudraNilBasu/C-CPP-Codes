#include<stdio.h>
#include<iostream>
#define ll long long int

using namespace std;

ll min(ll a, ll b)
{
    if(a<=b)
    return a;
    return b;
}

ll max(ll a, ll b)
{
    if(a>=b)
    return a;
    return b;
}

int main()
{
    ll l1,r1,l2,r2,k;
    cin >> l1 >> r1 >> l2 >> r2 >> k ;
    ll min_start,min_end;
    min_start=max(l1,l2);
    min_end=min(r1,r2);
    ll ans=0;
    ans=min_end-min_start+1;
    if(k>=min_start && k<=min_end) {
        ans--;
    }
    if(ans<0) {
    	printf("0\n");
	return 0;
    }
    //printf("%lld\n",ans);
	cout << ans << endl;
    return 0;
}

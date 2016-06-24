#include<stdio.h>
#define ll long long int
using namespace std;
int main()
{
	ll w,h;
	ll ans;
	while(1) {
		scanf("%lld %lld",&w,&h);
		if(w==0 && h==0)
			break;
		// w should be the lowest.
		if(w>h) {
			ll temp=w;
			w=h;
			h=temp;
		}
		if(h%w==0) {
			printf("%lld\n",(h/w));
		} else {
			ans=w*h;
			printf("%lld\n",ans);
		}
	}
	return 0;
}

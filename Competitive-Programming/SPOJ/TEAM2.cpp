#include<stdio.h>
#include<algorithm>
#define ll long long int
using namespace std;
int main()
{
	ll a[4];
	ll c=1;
	while( scanf("%lld %lld %lld %lld",&a[0],&a[1],&a[2],&a[3])!= EOF ) {
		sort(a,a+4);
		printf("Case %lld: %lld\n",(c++),(a[3]+a[2]));
	}
	return 0;
}

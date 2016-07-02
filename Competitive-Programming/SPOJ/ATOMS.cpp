#include <iostream>
#include<stdio.h>
#include<math.h>
#define ll long long int
using namespace std;
 
int check(ll n,ll k, ll m) 
{
	float t=0;
	if(n>m) {
		printf("0\n");
		return 0;
	}
	float ans = m/n;
	t = log10(ans) / log10 (k);
	printf("%lld\n",(ll)t);
}
 
int main() {
	int p;
	ll n,k,m;
	scanf("%d",&p);
	while(p--) {
		scanf("%lld %lld %lld",&n,&k,&m);
		check(n,k,m);
	}
	return 0;
}

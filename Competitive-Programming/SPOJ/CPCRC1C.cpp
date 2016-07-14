#include<stdio.h>
#include<math.h>
#include<string.h>
#define ll long long int
using namespace std;
ll sumDigit2(ll n)
{
	if(n<10)
		return n*(n+1)/2;
	int i=0;
	ll m=n;
	while(m/10!=0) {
		i++;
		m/=10;
	}
	int p = pow(10,i);
	return ((m*45*i*p/10)+ m*(m-1)*p/2+ m*(n%p+1) + sumDigit2(n%p));
}
int main()
{
	ll a,b,i,sum;
	while(1) {
		scanf("%lld %lld",&a,&b);
		if(a==-1 && b==-1)
			break;
		sum=sumDigit2(b)-sumDigit2(a-1);
		printf("%lld\n",sum);
	}
	return 0;
}

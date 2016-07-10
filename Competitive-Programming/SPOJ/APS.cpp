#include<stdio.h>
#include<vector>
#include<string.h>
#include<time.h>
#define ll long long int
#define ull unsigned ll
using namespace std;
ll primes[10000001];
ll a[10000001];
int sieve()
{
	ll i,j;
	for(i=0;i<10000001;i++) {
		primes[i]=1; // 1 meaning prime
	}
	primes[1]=0;
	for(i=2;i<10000001;i++) {
		if( primes[i]==1 ) {
			for(j=i+i;j<10000001;j+=i) {
				if(primes[j]==1)
					primes[j]=i;
			}
		}
		if(i==2) {
			a[i]=2;
		} else {
			if(primes[i]==1) {
				a[i]=a[i-1]+i;
			} else {
				a[i]=a[i-1]+primes[i];
			}
		}
	}
}
int main()
{
	//clock_t tic = clock();
	sieve();
	a[1]=0;
	//clock_t toc = clock();
	//printf("Elapsed: %f seconds\n",(double)(toc-tic)/CLOCKS_PER_SEC);
	int t;
	scanf("%d",&t);
	while(t--) {
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",a[n]);
	}
	return 0;
}

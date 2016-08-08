#include<stdio.h>
#include<algorithm>
#define ll long long int
using namespace std;
int main()
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	ll c[n];
	for(i=0;i<n;i++) {
		scanf("%lld",&c[i]);
	}
	sort(c,c+n);
	reverse(c,c+n);
	ll sum=0;
	if(n<=k) {
		for(i=0;i<n;i++) {
			sum+=c[i];
		}
		printf("%lld\n",sum);
		return 0;
	}
	/*
	for(i=0;i<k;i++) {
		sum+=c[i];
	}
	int noOfRounds=n/k;
	sum=((noOfRounds*(noOfRounds+1))/2)*sum;
	*/
	int rounds=1,noOfRounds=n/k;;
	for(rounds=1;rounds<=noOfRounds;rounds++) {
		for(i=0;i<k;i++) {
			sum+=(rounds)*c[((rounds-1)*k)+i];
		}
	}
	// Add remaining part
	for(i=(noOfRounds)*k;i<n;i++) {
		sum+=(noOfRounds+1)*c[i];
	}
	printf("%lld\n",sum);
	return 0;
}

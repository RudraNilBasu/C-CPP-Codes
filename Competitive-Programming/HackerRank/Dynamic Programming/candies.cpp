#include<stdio.h>
#define ll long long int
int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}
using namespace std;
int main()
{
	int n,i;
	scanf("%d",&n);
	int rating[n];
	for(i=0;i<n;i++) {
		scanf("%d",&rating[i]);
	}
	int candies[n];
	int candies2[n];
	for(i=0;i<n;i++) {
		candies[i]=1;
		candies2[i]=1;
	}
	for(i=1;i<n;i++) {
		if(rating[i]>rating[i-1]) {
			candies[i]=candies[i-1]+1;
		}
	}
	for(i=n-2;i>=0;i--) {
		if(rating[i]>rating[i+1]) {
			candies2[i]=candies2[i+1]+1;
		}
	}
	ll sum=0;
	for(i=0;i<n;i++) {
		sum+=max(candies[i], candies2[i]);
	}
	printf("%lld\n",sum);
	return 0;
}

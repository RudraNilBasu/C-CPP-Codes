#include<stdio.h>
#include<stdlib.h>

#define ll long long int

using namespace std;


int n;
int *price;
void calc()
{
	int max=price[n-1];
	ll profit=0;
	int i;
	for(i=n-2;i>=0;i--) {
		if(price[i]>max) {
			max=price[i];
			continue;
		} else {
			profit+=(max-price[i]);
		}
	}
	printf("%lld\n",profit);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		price = new int [n];
		for(i=0;i<n;i++) {
			scanf("%d",&price[i]);
		}
		calc();
	}
}

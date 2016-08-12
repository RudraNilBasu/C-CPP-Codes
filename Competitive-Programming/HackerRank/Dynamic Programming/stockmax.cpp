#include<stdio.h>

#define ll long long int

using namespace std;

int dp[50001];

int n;
int *price;

int max2(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}
int max3(int a, int b, int c)
{
	return max2( a, max2(b,c) );
}

ll profit(int totalStock, int day, int cost, int sell)
{
	// totalStock = no of stocks we have 
	// bought upto now
	// day = day no starting from 0 (index
	// of price[] )
	// cost = total cost used till now
	// sell = amt sold till now
	if(day==n-1) {
		return (totalStock*price[day] + sell) - cost;
	}
	int i,maxStocks;
	maxStocks=-9999;
	for(i=1;i<=totalStock;i++) {
		maxStocks = max2(
				maxStocks,
				profit(totalStock-1, day+1, cost, sell+(price[day]*i))
				);
	}
	return 
		max3(
			profit(totalStock+1, day+1, (cost+price[day]), sell),
			profit(totalStock, day+1, cost, sell),
			maxStocks
				);
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
		printf("%lld\n",profit(0,0,0,0));
	}
}

/*
ll profit(int totalStock, int day, int cost)
{
	// totalStock = no of stocks we have 
	// bought upto now
	// day = day no starting from 0 (index
	// of price[] )
	// cost = total cost used till now
	if(day==n-1) {
		return totalStock*price[day] - cost;
	}
	int i,maxStocks;
	maxStocks=-9999;
	for(i=1;i<=totalStocks;i++) {
		maxStocks = max2(
				maxStocks,
				profit(totalStock-1, day+1, (price[day]*i)-cost)
				);
	}
	return 
		max3(
			profit(totalStock+1, day+1, (cost+price[day])),
			profit(totalStock, day+1, cost),
			maxStocks
				);
}
*/

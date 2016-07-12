#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long int
using namespace std;
typedef struct aticket {
	int start;
	int duration;
	int price;
}ticket;

int cmp(aticket a, aticket b)
{
	return a.start < b.start;
}
int n;
int dp[10001][10001];
ll calc(int start, int end, ticket disc[])
{
	if(start>end)
		return 0;
	if(dp[start][end]!=-1)
		return dp[start][end];
	if(start==end)
		return dp[start][end]=disc[start].price;
	int i,pos=disc[start].start+disc[start].duration;
	for(i=start;i<n;i++) {
		if(disc[i].start>=pos)
			break;
	}
	return dp[start][end] = max(
			disc[start].price+calc(i,end,disc),
			calc(start+1,end,disc)
			);
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--) {
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		ticket disc[n];
		for(i=0;i<n;i++) {
			scanf("%d %d %d",&disc[i].start,&disc[i].duration,&disc[i].price);
		}
		sort(disc,disc+n,cmp);
		printf("%lld\n",calc(0,n-1,disc));
	}
	return 0;
}

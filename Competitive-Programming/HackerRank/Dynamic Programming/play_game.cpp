#include<stdio.h>

#define ll long long int
using namespace std;

int n;
ll *a;

ll max2(ll a, ll b)
{
	if(a>=b)
		return a;
	return b;
}
ll max3(ll a, ll b, ll c)
{
	//printf("Max between %lld, %lld, %lld is %lld\n",a,b,c,max2(a, max2(b,c)));
	return max2( a, max2(b,c) );
}


ll maxScore(int player, int index)
{
	//printf("Index = %d\n", index);
	if(index>=n)
	{
		return 0;
	}

	if(index==(n-1))
	{
		if(player) {
			return a[n-1];
		} else {
			return 0;
		}
	}
	if(index==(n-2))
	{
		if(player)
		return a[n-2]+a[n-1];
		else 
			return 0;
	}
	if(index==(n-3))
	{
		if(player)
		return a[n-3]+a[n-2]+a[n-1];
		else 
			return =0;
	}

	//printf("Player %d Index %d\n",player, index);
	if(player) {
		return 
			max3(
				a[index]+maxScore(!player, index+1),
				a[index]+a[index+1]+maxScore(!player, index+2),
				a[index]+a[index+1]+a[index+2]+maxScore(!player, index+3)
			   );
	} else {
		return 
			max3(
				maxScore(!player, index+1),
				maxScore(!player, index+2),
				maxScore(!player, index+3)
			   );
	}
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		a = new ll[n];
		for(i=0;i<n;i++) {
			scanf("%lld",&a[i]);
		}
		printf("%lld\n",maxScore(1,0));
		printf("test %lld\n",maxScore(0,1));
		printf("HUe %lld\n",max3( maxScore(0,1), maxScore(0,2), maxScore(0,3)  ));
	}
	return 0;
}

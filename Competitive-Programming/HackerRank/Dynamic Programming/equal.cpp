#include<stdio.h>
#include<string.h>
#include<limits.h>

#define ll long long int

ll dp[10000][3];
//int *a;
int n;

ll min2(ll a, ll b)
{
	if(a<=b)
		return a;
	return b;
}

ll min3(ll a, ll b, ll c)
{
	return min2( a, min2(b,c) );
}

ll solve(int a[], int no, int ign)
{
	// no = no to add
	// step = current step no (-1 in start)
	// ign = index to ignore
	//step++;
	int i;
	for(i=0;i<n;i++) {
		if(i==ign)
			continue;
		a[i]+=no;
	}
	// checking if all nos are equal
	bool isEqual=true;
	for(i=1;i<n;i++) {
		printf("%d, (%d, %d) ",a[i], i, n);
		if(a[i]!=a[0]) {
			isEqual=false;
			break;
		}
	}
	printf("\n");return 0;
	if(isEqual) {
		//printf("haha %d\n",ign);
		return 0;
	}

	ll ans=INT_MAX,part;
	printf("hola\n");
	for(i=0;i<n;i++) {
		// either choose this or ignore
		part=min3(
			1+solve(a, 1, i),
			1+solve(a, 2, i),
			1+solve(a, 5, i)
				);
		ans=min2(ans, part);
	}
	return ans;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		//a = new int[n];
		int a[n];
		for(i=0;i<n;i++) {
			scanf("%d",a+i);
		}
		printf("%lld\n",solve(a, 0, 0));
	}
	return 0;
}

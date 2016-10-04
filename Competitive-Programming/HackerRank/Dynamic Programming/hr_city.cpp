#include<stdio.h>

#define ll long long int
#define MOD 1000000007

ll solve(int n)
{
	if(n==1) {
		return 0;
	}
	return 4*solve(n-1) + ;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	return 0;
}

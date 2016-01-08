//http://www.spoj.com/problems/OLOLO/
#include<stdio.h>
#include<stdlib.h>
#define ll long long
int main()
{
	int n,i,s=0;
	scanf("%d",&n);
	ll *a=(ll *)malloc(n*sizeof(ll));
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		s=s^a[i];
	}
	printf("%d\n",s);
	return 0;
}

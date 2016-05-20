#include<stdio.h>
#include<string.h>
#define ll long long int
using namespace std;
ll f[100001];
int fillup()
{
	int i,j;
	memset(f,0,sizeof(f));
	for(i=1;i<=100001;i+=2)
	{
		for(j=i;j<=100001;j+=i)
		{
			f[j]+=i;
		}
	}
	return 0;
}
int main()
{
	fillup();
	int t,l,r,i;
	ll sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&l,&r);
		sum=0;
		for(i=l;i<=r;i++)
			sum+=f[i];
		printf("%lld\n",sum);
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,n,u,i,q,x,l,r,val;
	long long int ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&u);
		int a[n];
		int add[n+1];
		memset(add,0,sizeof(add));
		for(i=0;i<u;i++) {
			scanf("%d %d %d",&l,&r,&val);
			add[l]+=val;
			add[r+1]-=val;
		}
		int sum=0;
		for(i=0;i<n;i++) {
			sum+=add[i];
			a[i]=sum;
		}
		scanf("%d",&q);
		while(q--) {
			scanf("%d",&x);
			printf("%d\n",a[x]);
		}
	}
}

#include<stdio.h>
#include<algorithm>
#include<limits.h>
#define ll long long int
using namespace std;
int main()
{
	int t,n,i,j,pos,flag;
	ll k,no;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %lld",&n,&k);
		ll a[n],b[n];
		for(i=0;i<n;i++) {
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++) {
			scanf("%lld",&b[i]);
		}
		sort(b,b+n);
		flag=0;
		for(i=0;i<n;i++) {
			// fill a[i] with min value st a[i]+b[i]>=k
			no=LLONG_MAX; // min no from i...n st a[i]+b[i]>=k
			pos=-1;
			for(j=i;j<n;j++) {
				if( (a[j]+b[i])>=k && no>a[j] ) {
					no=a[j];
					pos=j;
				}
			}
			if(pos==-1) {
				flag=1;
				break;
			} else {
				ll temp=a[pos];
				a[pos]=a[i];
				a[i]=temp;
			}
		}
		if(flag) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}

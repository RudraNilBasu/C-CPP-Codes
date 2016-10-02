#include<stdio.h>
 
#define ull unsigned long long int
 
using namespace std;
 
int main()
{
	ull t,n,i,sum;
	scanf("%llu",&t);
	while(t--) {
		scanf("%llu",&n);
		ull a[n];
		sum=0;
		for(i=0;i<n;i++) {
			scanf("%llu",a+i);
			sum=(sum%n+a[i]%n)%n;
		}
		if(sum==0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}	
	return 0;
}

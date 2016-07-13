#include<stdio.h>
using namespace std;
int main()
{
	int t,i,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int a[n];
		bool fv=false;
		bool fail=false;
		float avg=0;
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if(a[i]==5)
				fv=true;
			avg+=a[i];
			if(a[i]==2)
				fail=true;
		}
		avg=avg/n;
		if(!fail && fv && avg>=4) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}

#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i,ans;
	char coin[5];
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++) {
			scanf("%s",coin);
			if(coin[0]=='l') {
				a[i]=1;
			} else if(coin[0]=='h') {
				a[i]=0;
			}
		}
		ans=a[0];
		for(i=1;i<n;i++) {
			ans = ans ^ a[i];
		}
		if(ans==0) {
			printf("hhb\n");
		} else if(ans==1) {
			printf("lxh\n");
		}
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define ll long long int

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

using namespace std;

bool isAP(int a[], int n)
{
	if(n==2) {
		return true;
	}
	int i,diff=a[1]-a[0];
	for(i=2;i<n;i++) {
		if((a[i]-a[i-1])!=diff) {
			return false;
		}
	}
	return true;
}

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++) {
			scanf("%d",a+i);
		}
		if(isAP(a,n)) {
			printf("%d\n",a[0]);
			continue;
		} else {
			int frontDiff=a[1]-a[0];
			int frontVal=-1;
			int backVal=-1;
			int backDiff=a[n-1]-a[n-2];
			if(frontDiff!=backDiff) {
				printf("-1\n");
				continue;
			}
			for(i=2;i<n;i++) {
				if((a[i]-a[i-1])!=frontDiff) {
					frontVal=i;
					break;
				}
			}
			for(i=n-2;i>0;i--) {
				if((a[i+1]-a[i])!=backDiff) {
					backVal=i;
					break;
				}
			}
			if(frontVal!=backVal) {
				printf("-1\n");
				continue;
			} else {
				printf("%d\n",a[frontVal]);
			}
		}
	}
	return 0;
}


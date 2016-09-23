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

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) {
		scanf("%d",a+i);
	}
	if(n==1) {
		if(a[0]==15) {
			printf("DOWN\n");
			return 0;
		}
		if(a[0]==0) {
			printf("UP\n");
			return 0;
		}
		printf("-1\n");
		return 0;
	}
	int diff=0;
	diff=a[n-1]-a[n-2];
	if(diff>0) {
		// general case
		if(a[n-1]!=15) {
			printf("UP\n");
			return 0;
		}
		// if last digit is 13
		if(a[n-1]==15) {
			printf("DOWN\n");
			return 0;
		}
	} else if(diff<0) {
		if(a[n-1]!=0) {
			printf("DOWN\n");
		} else if(a[n-1]==0) {
			printf("UP\n");
		}
		return 0;
	}
	return 0;
}


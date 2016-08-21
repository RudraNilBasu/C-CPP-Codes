#include<stdio.h>
#include<limits.h>

#define ERR 0.001
#define PI 3.14159265358979323846264338327950

using namespace std;

bool isPossible(float no, int rad[], int n, int k)
{
	float cp[n];
	int count=0,i;
	for(i=0;i<n;i++) {
		cp[i]=rad[i];
	}
	for(i=0;i<n;) {
		//
	}
}

int main()
{
	int t,n,k,i,min;
	float low,high,mid;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&k);
		int rad[n];
		min=INT_MAX;
		for(i=0;i<n;i++) {
			scanf("%d",&rad[i]);
			if(min>rad[i]) {
				min=rad[i];
			}
		}
		// answer is somewhere between min and 0
		low = 0;
		high = min;
		while(low<high && (high-low)>ERR) {
			// high = Not possible
			// low  = Possible
			mid=(low+high)/2.0;
			if(isPossible(mid, rad, n, k)) {
				low=mid;
			} else {
				high=mid;
			}
		}
		printf("%f\n", PI*mid*mid);
	}
	return 0;
}

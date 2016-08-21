#include<stdio.h>
#include<limits.h>
#include<math.h>

#define ERR 0.001
#define PI 3.14159265358979323846264338327950
#define float double

// xD float caused TLE, use double instead 

using namespace std;

float vol(float n)
{
	return PI*n*n;
}

bool isPossible(float no, int rad[], int n, int k)
{
	// whether it is possible to divide cakes
	// to k people if the radius is no
	float cp[n];
	int count=0,i;
	for(i=0;i<n;i++) {
		cp[i]=rad[i]*1.0;
	}
	for(i=0;i<n;i++) {
		count+=(cp[i]*cp[i])/(no*no);
		if(count>=k) {
			return true;
		}
	}
	if(count>=k) {
		return true;
	}
	return false;
}

int main()
{
	int t,n,k,i,min,up;
	float low,high,mid;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&k);
		int rad[n];
		min=INT_MAX;
		up=-1;
		for(i=0;i<n;i++) {
			scanf("%d",&rad[i]);
			if(min>rad[i]) {
				min=rad[i];
			}
			if(up<rad[i]) {
				up=rad[i];
			}
		}
		// answer is somewhere between min and 0
		low = 0;
		//high = min;
		high=up;
		while(low<high && (vol(high)-vol(low))>=ERR) {
			// high = Not possible
			// low  = Possible
			mid=(low+high)/2.0;
			if(isPossible(mid, rad, n, k+1)) {
				low=mid;
			} else {
				high=mid;
			}
		}
		//printf("Radius = %f\n",mid);
		printf("%f\n", PI*mid*mid);
	}
	return 0;
}

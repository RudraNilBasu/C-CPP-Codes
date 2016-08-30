#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

#define ll long long int
#define linf 0x3f3f3f3f3f3f3f3fLL
//#define linf LLONG_MAX

int *a;
int n;

int mod(int n)
{
	if(n<0)
		return n*-1;
	return n;
}

bool check(ll x)
{
	int i;
	for(i=0;i<n;i++) {
		//printf("x=%d\ta[i]=%d\n",x,a[i]);
		//if(a[i]>x) {
		/*
		if(x<0) {	
			return false;
		}
		*/
		//printf("Adding %d\n",mod(x-a[i]));
		//x+=mod(x-a[i]);
		x = x + (x-a[i]);
		if(x>=linf)
			return true;
		if(x<0)
			return false;
		//printf("x is now=%d\n",x);
	}
	/*
	if(x<0)
		return false;
	*/
	return true;
}

int main() {
	int i, max=-1;
	scanf("%d",&n);
	//int a[n];
	a=new int[n];
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
		if(max<a[i]) {
			max=a[i];
		}
	}
	
	//printf("%d\n",check(51180));
	//printf("%d\n",max);
	
	ll low, high, mid;
	//low=a[0];
	low=0;
	high=linf;
	//high=max;
	while(low<high) {
		mid=(low+high)/2;
		if(check(mid)) {
			high=mid;
		} else {
			low=mid+1;
		}
	}
	printf("%lld\n",high);
	
	/*
	int energy=0;
	for(i=n-1;i>=0;i--) {
		energy = (energy+a[i]+1)/2;
	}
	printf("%d\n",energy);
	*/
	return 0;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int *a;
int n;

int mod(int n)
{
	if(n<0)
		return n*-1;
	return n;
}

bool check(int x)
{
	int i;
	for(i=0;i<n;i++) {
		//printf("x=%d\ta[i]=%d\n",x,a[i]);
		//if(a[i]>x) {
		if(x<0) {	
			return false;
		}
		//printf("Adding %d\n",mod(x-a[i]));
		//x+=mod(x-a[i]);
		x = x + (x-a[i]);
		//printf("x is now=%d\n",x);
	}
	if(x<0)
		return false;
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
	//printf("%d\n",check(1859));
	//printf("%d\n",max);
	
	int low, high, mid;
	low=a[0];
	high=max;
	while(low<high) {
		mid=(low+high)/2;
		if(check(mid)) {
			high=mid;
		} else {
			low=mid+1;
		}
	}
	printf("%d\n",high);
	
	return 0;
}


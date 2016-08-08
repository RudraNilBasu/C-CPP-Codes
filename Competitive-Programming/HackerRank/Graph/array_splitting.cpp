#include<stdio.h>
#define ll long long int
using namespace std;
int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}
ll getSum(ll a[], int n)
{
	ll count=0;
	int i;
	for(i=0;i<n;i++) {
		count+=a[i];
	}
	return count;
}
int getPoints(ll a[], int n)
{
	ll sum=getSum(a,n);
	if(sum==0) {
		return n-1;
	}
	if(sum%2) {
		return 0;
	} else {
		ll reqdSum=sum/2;
		ll count=0;
		int i,flag=0;
		for(i=0;i<n;i++) {
			count+=a[i];
			if(count==reqdSum) {
				flag=1;
				break;
			}
		}
		if(flag==0) {
			return 0;
		}
		int left,right,j,k;
		left=i+1;
		right=n-(i+1);
		/*
		if(left>right) {
			ll arr[left];
			k=0;
			for(j=0;j<=i;j++) {
				arr[k++]=a[j];
			}
			return 1+getPoints(arr,left);
		} else {
			ll arr[right];
			k=0;
			for(j=i+1;j<n;j++) {
				arr[k++]=a[j];
			}
			return 1+getPoints(arr,right);
		}
		*/
		ll al[left],ar[right];
		k=0;
		for(j=0;j<=i;j++) {
			al[k++]=a[j];
		}
		k=0;
		for(j=i+1;j<n;j++) {
			ar[k++]=a[j];
		}
		return 1+max( getPoints(al,left), getPoints(ar,right) );
	}
}
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		ll a[n];
		for(i=0;i<n;i++) {
			scanf("%lld",&a[i]);
		}
		printf("%d\n",getPoints(a,n));
	}
	return 0;
}

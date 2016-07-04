#include<stdio.h>
#define ull unsigned long long int
using namespace std;
ull merge(int a[], int left, int mid, int right)
{
	int n1,n2;
	ull inv=0;
	n1=mid-left+1;;
	n2=right-mid;
	int L[n1];
	int R[n2];
	int i,j,k;
	for(i=0;i<n1;i++) {
		L[i]=a[left+i];
	}
	for(i=0;i<n2;i++) {
		R[i]=a[mid+1+i];
	}
	i=0;
	j=0;
	k=left;
	while(i<n1 && j<n2) {
		if(L[i]<=R[j]) {
			a[k]=L[i];
			i++;
		} else {
			a[k]=R[j];
			j++;
			inv+=(mid-i-left+1);
		}
		k++;
	}
	while(i<n1) {
		a[k]=L[i];
		k++;
		i++;
	} 
	while(j<n2) {
		a[k]=R[j];
		k++;
		j++;
	}
	return inv;
}
ull mergesort(int a[],int size, int left, int right)
{
	int mid;
	ull inv=0;
	if(left<right) {
		mid=(left+right)/2;
		inv=mergesort(a,size,left,mid);
		inv+=mergesort(a,size,mid+1,right);
		inv+=merge(a,left,mid,right);
	}
	return inv;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,i;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		printf("%llu\n",mergesort(a,n,0,n-1));
	}
	return 0;
}

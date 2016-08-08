#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int cost=1,cmp=a[0];
	for(i=0;i<n;i++) {
		if(a[i] > cmp+4) {
			cost++;
			cmp=a[i];
		}
	}
	printf("%d\n",cost);
	return 0;
}

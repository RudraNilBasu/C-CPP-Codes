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
	int n,k,i;
	scanf("%d %d",&n,&k);
	int a[n];
	int b[n];
	for(i=0;i<n;i++) {
		scanf("%d",a+i);
		b[i]=a[i];
	}
	/*
	for(i=0;i<n-1;i++) {
		if(b[i]+b[i+1]>=k) {
			continue;
		} else {
			if(i<n-2) {
				if(b[i+1]+b[i+2]>=k) {
					b[i]=k-b[i+1];
					continue;
					
					
				} else {
					int l=k-(b[i+1]+b[i]);
					int l2=k-(b[i+1]+b[i+2]);
					int m=k-(b[i+1]+min(b[i],b[i+2]));
					if(m<=(l2+l)) {
						b[i+1]+=m;
						//continue;
					} else {
						b[i]+=l;
						b[i+2]+=l2;
						i=i+2;
						//continue;
					}
				}
			} else {
				if(b[i]>b[i+1]) {
					b[i]=k-b[i+1];
				} else {
					b[i+1]=k-b[i];
				}
			}
		}
	}
	*/
	for(i=0;i<n-1;i++) {
		if(b[i]+b[i+1]<k) {
			b[i+1]+=k-(b[i]+b[i+1]);
		}
	}
	int diff=0;
	for(i=0;i<n;i++) {
		diff+=b[i]-a[i];
	}
	printf("%d\n",diff);
	for(i=0;i<n;i++) {
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}

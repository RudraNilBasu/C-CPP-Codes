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

int calc(int a[], int n)
{
	int i,sum=0;
	for(i=0;i<n;i++) {
		sum+=a[i];
	}
	float temp=(sum*1.0)/n;
	if((temp-(int)temp)!=0) {
		printf("-1\n");
		return 0;
	}
	int avg=sum/n;
	int count=0;
	for(i=0;i<n;i++) {
		if(avg>a[i]) {
			count+=(avg-a[i]);
		}
	}
	printf("%d\n",count);
}

int main()
{
	int n,i;
	while(1) {
		scanf("%d",&n);
		if(n==-1) {
			break;
		}
		int a[n];
		for(i=0;i<n;i++) {
			scanf("%d",a+i);
		}
		calc(a,n);
	}
	return 0;
}


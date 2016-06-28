#include<stdio.h>
#include<string.h>
using namespace std;
int a[34000];
int lucky[3001];
int create()
{
	int i,j,k=0,m;
	for(i=0;i<33810;i++)
		a[i]=1;
	// a[i]=1 => i is a lucky no
	for(i=2;i<33810;i++) {
		if( a[i]==1 ) {
			lucky[k++]=i;
			// mark all
			int count=0;
			for(j=i+1;j<33810;j++) {
				if(a[j]==1)
					count++;
				if(count%i==0)
					a[j]=0;
			}
		}
	}
}
int main()
{
	create();
	int n;
	while(1) {
		scanf("%d",&n);
		if(n==0)
			break;
		printf("%d\n",lucky[n-1]);
	}
	return 0;
}

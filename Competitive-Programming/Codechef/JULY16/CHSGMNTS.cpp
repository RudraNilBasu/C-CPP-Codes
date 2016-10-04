#include<stdio.h>
#include<map>
#define ll long long int
using namespace std;
int main()
{
	int t,n,a,b,c,d,count,i,j;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int arr[n];
		for(i=0;i<n;i++) {
			scanf("%d",&arr[i]);
		}
		count=0;
		for(a=0;a<n;a++) {
			map<ll,int> left;
			for(b=a;b<n;b++) {
				left[ arr[b] ]=1;
				for(c=b+1;c<n;c++) {
					for(d=c;d<n;d++) {
						if( left[ arr[d] ] ) {
							break;
						}
						count++;
						//int flag=0;
						/*
						for(i=a;i<=b && !flag;i++) {
							for(j=c;j<=d;j++) {
								if(arr[i]==arr[j]) {
									flag=1;
									break;
								}
							}
						}
						*/
						/*
						map<ll,int> mp;
						for(i=a;i<=b;i++) {
							mp[arr[i]]=1;
						}
						for(i=c;i<=d;i++) {
							if( mp[arr[i]]==1 ) {
								flag=1;
								break;
							}
						}
						if(flag==0) {
							count++;
						}
						*/
					}
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

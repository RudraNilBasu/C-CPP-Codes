#include<stdio.h>
using namespace std;
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		int p=((n-m) & ((m-1)/2));
		if(p==0) {
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}

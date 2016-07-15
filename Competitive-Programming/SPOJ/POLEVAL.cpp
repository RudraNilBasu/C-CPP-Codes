#include<stdio.h>
#include<math.h>
#define ll long long int
#define ull unsigned ll
using namespace std;
typedef struct node{
	int deg;
	ll coeff;
}node;
int main()
{
	int n,i,x;
	ll sum,cse=1;
	while(1) {
		scanf("%d",&n);
		if(n==-1)
			break;
		node eqn[n+2];
		for(i=1;i<=(n+1);i++) {
			scanf("%lld",&eqn[i].coeff);
			eqn[i].deg = (n+1) - i;
		}
		int k;
		sum=0;
		scanf("%d",&k);
		printf("Case %lld:\n",cse);
		/*
		   pow() function slows things down!

		while(k--) {
			sum=0;
			scanf("%d",&x);
			for(i=1;i<=(n+1);i++) {
				sum+=(eqn[i].coeff*pow(x,eqn[i].deg));
			}
			printf("%lld\n",sum);
		}
		cse++;
		*/
		while(k--) {
			sum=0;
			scanf("%d",&x);
			ll mult=1;
			for(i=(n+1);i>=1;i--) {
				sum+=(eqn[i].coeff*mult);
				mult*=x;
			}
			printf("%lld\n",sum);
		}
		cse++;
	}
	return 0;
}

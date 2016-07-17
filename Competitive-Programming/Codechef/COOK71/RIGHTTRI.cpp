#include<stdio.h>
#include<math.h>
#define ll long long int
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		ll H,S;
		scanf("%lld %lld",&H,&S);
		if( (H*H)<(4*S) ) {
			printf("-1\n");
			continue;
		}
		printf("%.5lf %.5lf %lld.00000\n",(sqrt(H*H+4*S)-sqrt(H*H-4*S))/2,(sqrt(H*H+4*S)+sqrt(H*H-4*S))/2,H);
	}
	return 0;
}

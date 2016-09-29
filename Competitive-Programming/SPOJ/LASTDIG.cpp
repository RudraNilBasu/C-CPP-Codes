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
	int t;
	scanf("%d",&t);
	while(t--) {
		ll a,b;
		scanf("%lld %lld",&a,&b);
		int last=a%10;
		if(b==0) {
			printf("1\n");
			continue;
		}
		ll exp=b%4;
		if(exp==0) {
			exp=4;
		}
		printf("%d\n",((int)pow(last,exp))%10);
	}
	return 0;
}


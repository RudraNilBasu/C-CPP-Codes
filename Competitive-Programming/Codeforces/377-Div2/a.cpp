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
	int k,r;
	scanf("%d %d",&k,&r);
	int x=1;
	while(1) {
		if(((k*x)-r)%10==0 ) {
			break;
		}
		if((k*x)%10==0) {
			break;
		}
		x++;
	}
	printf("%d\n",x);
	return 0;
}


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

vector<float> g;

int calc()
{
	/*
	g.push_back(0);
	g.push_back(2.0/3.0);
	ll i;
	float s;
	for(i=2;i<=1000000000;i++) {
		s=g[i-1]+(((i+1.0)/(i+2.0))-(((i-1.0)+1.0)/((i-1.0)+2.0)))/(i*1.0);
		g.push_back(s);
	}
	*/
}

int main()
{
	calc();
	int t;
	ll n;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		printf("%.11f\n",g[n]);
	}
	return 0;
}


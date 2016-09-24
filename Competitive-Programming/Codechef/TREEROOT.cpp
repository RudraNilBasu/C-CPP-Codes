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

int calc()
{
	int n,id,sid,sum1,sum2;
	scanf("%d",&n);
	sum1=0;
	sum2=0;
	while(n--) {
		scanf("%d %d",&id,&sid);
		sum1+=id;
		sum2+=sid;
	}
	printf("%d\n",(sum1-sum2));
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		calc();
	}
	return 0;
}


#include<stdio.h>
#include <cstdlib>
#include <cstring>
using namespace std;
int n,k;
int hash[100];
int memo[50][50];
int init()
{
	memset(hash, 0, sizeof(hash));
	memset(memo, 0xff, sizeof(memo));
}

long long f(int i, int j)
{
	if(i>2*n) return j==0?1:0;
	if (memo[i][j] != -1) return memo[i][j];
	return memo[i][j] = f(i+1, j+1) + (hash[i] || j == 0 ? 0 : f(i+1, j-1));
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		init();
		for(i=0;i<k;i++)
		{
			int x;
			scanf("%d",&x);
			hash[x]=1;
		}
		printf("%lld\n",f(1,0));
	}
	return 0;
}

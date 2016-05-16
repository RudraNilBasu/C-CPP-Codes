#include<stdio.h>
#include<string.h>
#define MOD 1000000007
using namespace std;
int s,m,n;
int memo[1001][1001];
int chances(int currPos,int a[], int pos) // returns the number of ways ball can reach to dog n when the given power
{
	if(currPos<1 || currPos>n ) return 0;
	if(memo[currPos][pos]!=-1) return memo[currPos][pos];
	if(pos==0) // check this condition
	{
		// when only one pass is left
		if(currPos+a[pos]==s || currPos-a[pos]==s)
		{
			return memo[currPos][pos]=1;
		}
		return memo[currPos][pos]=0;
	}
	// more passes are left
	return memo[currPos][pos]=(chances(currPos-a[pos],a,pos-1)+chances(currPos+a[pos],a,pos-1))%MOD; // the number of possibilities on passing left + right
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&s);
		int power[m]; // to store the power 
		for(i=0;i<m;i++)
			scanf("%d",&power[i]);
		memset(memo,-1,sizeof(memo));
		for(i=1;i<=n;i++)
		{
			printf("%d ",chances(i,power,m-1));
		}
		printf("\n");
	}
	return 0;
}

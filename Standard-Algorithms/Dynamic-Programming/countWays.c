// Dividing a number n into 4  parts
// http://www.geeksforgeeks.org/count-number-of-ways-to-divide-a-number-in-4-parts/
#include<stdio.h>
#include<string.h>
int dp[5001][5001][5];
int count(int n,int parts,int nextPart) 
{
	// to return the no of possibilities for n,parts,nextPart

	// n - input
	// parts - no of parts 
	// starting number for the current part

	// base case
	if(n==0 && parts==0)
	return 1;
	if(n<=0||parts<=0)
	return 0;

	// returning if already calculated
	if(dp[n][parts][nextPart]!=-1)
	return dp[n][parts][nextPart];

	int i,ans=0; // the result
	for(i=nextPart;i<=n;i++)
	{
		ans+=count(n-i,parts-1,i);
	}
	return ans;
}
int countInit(int n,int parts)
{
	memset(dp,-1,sizeof(dp));
	return count(n,parts,1);
}
int main()
{
	int n,parts,ans=0;
	printf("Enter the number\n");
	scanf("%d",&n);
	printf("Enter the number of parts to be divided\n");
	scanf("%d",&parts);
	ans=countInit(n,parts);
	printf("No of parts = %d\n",ans);
	return 0;
}

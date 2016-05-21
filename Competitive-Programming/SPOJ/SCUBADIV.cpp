#include<stdio.h>
#include<limits.h>
#include<string.h>
#define INF INT_MAX
using namespace std;
int min(int a, int b)
{
	if(a<=b)
		return a;
	return b;
}
int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}
int main()
{
	int c,oxy,nitro,n,k,i,j;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&oxy,&nitro);
		scanf("%d",&n);
		//int o2[n],n2[n];
		int a[n+1][3];// for ith cylinder, a[i][0]=wt of 02
		// a[i][1]=wt of N2
		// a[i][2]=wt of each cylinder
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		}
		int dp[n+1][22][80];
		memset(dp,0,sizeof(dp));
		for(k=0;k<=n;k++)
		{
			for(i=0;i<=21;i++)
			{
				for(j=0;j<=79;j++)
				{
					if(k==0)
					{	
						dp[k][i][j]=1000000; // =infinity, this works just fine
						if(i==0 && j==0) dp[k][i][j]=0;
					}
					else
					{
						dp[k][i][j]=min(
								dp[k-1][i][j],
								a[k][2]+dp[k-1][max(0,i-a[k][0])][max(0,j-a[k][1])]
								);
					}
				}
			}
		}
		printf("%d\n",dp[n][oxy][nitro]);
		printf("\n"); // newline after each test case
	}
	return 0;
}

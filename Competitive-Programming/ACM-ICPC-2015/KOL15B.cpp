#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define ll long long int
#define MAXN 1000000007

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

using namespace std;

int a[1001][1001];
int n,m;

int minUp(int _i, int _j)
{
	int i,j=_j;
	//int count=a[_i][_j];
	int count=0;
	int minm=MAXN;
	for(i=_i-1;i>=0;i--) {
		/*
		if(count+a[i][j]<count) {
			count+=a[i][j];
			if(count<min) {
				min=count;
			}
		} else {
			//return count;
			count=0;
		}
		*/
		count+=a[i][j];
		if(minm>count) {
			minm=count;
		}
	}
	//return count;
	return min(0,minm);
}

int minDown(int _i, int _j)
{
	int i,j=_j;
	//int count=a[_i][_j];
	int count=0;
	int minm=MAXN;
	for(i=_i+1;i<n;i++) {
		/*
		if(count+a[i][j]<count) {
			count+=a[i][j];
			if(count<min) {
				min=count;
			}
		} else {
			//return count;
			count=0;
		}
		*/
		count+=a[i][j];
		if(minm>count) {
			minm=count;
		}
	}
	//return count;
	return min(0,minm);
}

int minLeft(int _i, int _j)
{
	int i=_i,j;
	int count=0;
	int minm=MAXN;
	for(j=_j-1;j>=0;j--) {
		/*
		if(count+a[i][j]<count) {
			count+=a[i][j];
			if(count<min) {
				min=count;
			}
		} else {
			//printf("Min Left for %d,%d is = %d\n",_i,_j,count);
			//return count;
			count=0;
		}
		*/
		count+=a[i][j];
		if(minm>count) {
			minm=count;
		}
	}
	//return count;
	return min(0,minm);
}

int minRight(int _i, int _j)
{
	int i=_i,j;
	int count=0;
	int minm=MAXN;
	for(j=_j+1;j<m;j++) {
		/*
		if(count+a[i][j]<count) {
			count+=a[i][j];
			if(count<min) {
				min=count;
			}
		} else {
			//return count;
			count=0;
		}
		*/
		count+=a[i][j];
		if(minm>count) {
			minm=count;
		}
	}
	return min(0,minm);
	//return count;
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		int dp[n][m];
		int up[n][m];
		int down[n][m];
		int left[n][m];
		int right[n][m];
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				scanf("%d",&a[i][j]);
				dp[i][j]=a[i][j];
				if(i==0) {
					//up[i][j]=min(0,a[i][j]);
					up[i][j]=a[i][j];
				} else {
					up[i][j]=min(0,up[i-1][j]+a[i][j]);
				}
				if(j==0) {
					//left[i][j]=min(0,a[i][j]);
					left[i][j]=a[i][j];
				} else {
					left[i][j]=min(0,left[i][j-1]+a[i][j]);
				}
			}
		}
		for(i=n-1;i>=0;i--) {
			for(j=m-1;j>=0;j--) {
				if(i==n-1) {
					//down[i][j]=min(0,a[i][j]);
					down[i][j]=a[i][j];
				} else {
					down[i][j]=min(0,down[i+1][j]+a[i][j]);
				}
				if(j==m-1) {
					//right[i][j]=min(0,a[i][j]);
					right[i][j]=a[i][j];
				} else {
					right[i][j]=min(0,right[i][j+1]+a[i][j]);
				}
			}
		}
		
		/*
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				printf("%d ",up[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				printf("%d ",right[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				printf("%d ",left[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				printf("%d ",down[i][j]);
			}
			printf("\n");
		}
		*/
		
		int ans=MAXN;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				//dp[i][j]=min( dp[i][j],
				//		a[i][j]+minLeft(i,j)+minRight(i,j)+minUp(i,j)+minDown(i,j)
				//		);
				//ans=min(ans,dp[i][j]);
				//printf("ans=%d\n",ans);	
				//dp[i][j]=a[i][j]+minLeft(i,j)+minRight(i,j)+minUp(i,j)+minDown(i,j);
				dp[i][j]=up[i][j]+down[i][j]+left[i][j]+right[i][j]-(3*a[i][j]);
				//printf("%d,%d\n%d+%d+%d+%d-%d=%d\n",i,j,up[i][j],down[i][j],left[i][j],right[i][j],(3*a[i][j]),dp[i][j]);
				ans=min(ans,dp[i][j]);
			}
		}
		/*
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}
		*/
		/*
		int ans=MAXN;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				ans=min(ans,dp[i][j]);
			}
		}
		*/
		printf("%d\n",ans);
	}
	return 0;
}


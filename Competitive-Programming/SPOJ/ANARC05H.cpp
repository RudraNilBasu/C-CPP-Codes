#include<stdio.h>
#include<string.h>
using namespace std;
char num[26];
int dp[26][256];
int calc(int index, int prev)
{
	if(index==strlen(num)) {
		return 1;
	}
	if(dp[index][prev]!=-1)
		return dp[index][prev];
	int i,sum=0,val=0;
	for(i=index;i<strlen(num);i++) {
		sum+=(num[i]-'0');
		if(sum>=prev) {
			val+=calc(i+1,sum);
		}
	}
	return dp[index][prev]=val;
}
int main()
{
	int k=1;
	while(1) {
		scanf("%s",num);
		if(strcmp(num,"bye")==0) {
			break;
		}
		memset(dp,-1,sizeof(dp));
		printf("%d. %d\n",k++,calc(0,0));
	}
	return 0;
}

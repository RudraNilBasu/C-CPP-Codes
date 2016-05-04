#include<stdio.h>
#include<string.h>
using namespace std;
int memo[201][201];
int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}
int calc(char a[], int st, int end)
{
	if(memo[st][end]!=-1) return memo[st][end];
	if(st==end)
	{
		if(a[st]=='0') return memo[st][end]=0;
		else return memo[st][end]=1;
	}
	int ones=0,zero=0;
	for(int k=st;k<=end;k++)
	{
		if(a[k]=='0')zero++;else ones++;
	}
	if(ones>zero)
		return memo[st][end]=(end-st+1);
	int i,x=-1;
	for(i=st;i<end;i++)
	{
		x=max(x,calc(a,st,i)+calc(a,i+1,end));
	}
	return memo[st][end]=x;
}
int main()
{
	int t,i,n;
	//int a[201];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(memo,-1,sizeof(memo));
		char a[n+1];
		scanf("%s",a);
		printf("%d\n",calc(a,0,n-1));
	}
	return 0;
}

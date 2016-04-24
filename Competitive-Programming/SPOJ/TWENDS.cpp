#include<stdio.h>
#include<string.h>
using namespace std;
int max(int a, int b)
{
	if(a>=b)
	return a;
	return b;
}
int pl; // the score of player and greedy
int a[1001];
int memo[1001][1001];
int f(int st,int end,char op)
{
	if(op=='g') // if it is greedy's turn
	{
		if(st==end)
		{
			//gr+=a[st];
			return 0;
		}
		if(a[st]>=a[end])
		{
			//gr+=a[st++];
			st++;
		}
		else
		{
			//gr+=a[end--];
			end--;
		}
		return f(st,end,'p');
	}
	else if(op=='p')
	{
		if(memo[st][end]!=-1) return memo[st][end];
		return memo[st][end]=max(
		a[st]+f(st+1,end,'g'),
		a[end]+f(st,end-1,'g')
		);
	}
}
int main()
{
	int n,i,sum,k=1;
	while(1)
	{
		scanf("%d",&n);
		sum=0;
		if(n==0) break;
		memset(memo,-1,sizeof(memo));
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}

		pl=0;

		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",k,2*f(0,n-1,'p')-sum);
		k++;
	}
}

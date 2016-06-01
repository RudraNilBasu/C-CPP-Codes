#include<stdio.h>
#include<string.h>
using namespace std;
int memo[101][11][44];
int f[44];
int calcF()
{
	f[0]=1;
	f[1]=2;
	int i;
	for(i=2;i<=43;i++)
		f[i]=f[i-1]+f[i-2];
}
int fillup()
{
	int x,k,n;
	calcF();
	//memset(memo,0,sizeof(memo));
	for(x=0;x<=100;x++)
	{
		for(k=0;k<=10;k++)
		{
			for(n=0;n<=43;n++)
			{
				if(k==0)
				{
					if(x==0)
						memo[x][k][n]=1;
					else
						memo[x][k][n]=0;
				}
				else if(x==0 || n==0)
					memo[x][k][n]=0;
				else
				{
					memo[x][k][n]=memo[x][k][n-1];
					if(x>=f[n-1])
						memo[x][k][n]+=memo[x-f[n-1]][k-1][n];
				}
			}
		}
	}
}
int main()
{
	int q,x,k;
	fillup();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&x,&k);
		//printf("%d\n",);
		printf("%d\n",memo[x][k][43]);
	}
	return 0;
}

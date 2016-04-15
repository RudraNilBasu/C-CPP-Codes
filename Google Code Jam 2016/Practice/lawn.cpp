// Solution of Lawnmower GCJ2013
#include<stdio.h>
using namespace std;
int main()
{
	int t,test,n,m,i,j,k,flag;
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		scanf("%d %d",&n,&m);
		int a[n][m];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		flag=0;
		for(i=0;i<n && !flag;i++)
		{
			for(j=0;j<m && !flag;j++)
			{
				// check if a[i][j] is max of either of it's row or col
				int row=0,col=0;
				// checking the row
				for(k=0;k<m;k++)
				{
					if(a[i][j]<a[i][k])
					{
						row++;
						break;
					}
				}
				// checking for col
				for(k=0;k<n;k++)
				{
					if(a[i][j]<a[k][j])
					{
						col++;
						break;
					}
				}
				if(row>0 && col>0)
				{
					flag=1;
				}
			}
		}
		if(flag)
		{
			printf("Case #%d: NO\n",t);
		}
		else
		{
			printf("Case #%d: YES\n",t);
		}
	}
	return 0;
}

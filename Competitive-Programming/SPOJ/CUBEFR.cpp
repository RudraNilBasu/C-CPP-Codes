#include<stdio.h>
using namespace std;
int cf(int n)
{
	int i=2;
	while((i*i*i)<=n)
	{
		if(n%(i*i*i)==0) return 0;
		i++;
	}
	return 1;
}
int main()
{
	int a[1000001];
	int i,k=1;
	for(i=1;i<1000001;i++)
	{
		if(cf(i)) a[i]=k++;
		else a[i]=-1;
	}
	int t,n;
	scanf("%d",&t);
	//while(t--)
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		if(a[n]==-1)
		{
			printf("Case %d: Not Cube Free\n",i);
		}
		else
		{
			printf("Case %d: %d\n",i,a[n]);
		}
	}
}

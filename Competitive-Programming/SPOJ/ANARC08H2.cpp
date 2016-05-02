#include<stdio.h>
using namespace std;
int main()
{
	while(1)
	{
		int n,m,i,s;
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		for(i=1;i<=n;i++)
		{
			if(i==1) s=1;
			else
				s=(s+(m-1))%i+1;
		}
		printf("%d %d %d\n",n,m,s);
	}
	return 0;
}

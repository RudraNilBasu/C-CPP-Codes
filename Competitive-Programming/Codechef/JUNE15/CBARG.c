//https://www.codechef.com/JUNE15/problems/CBARG
//https://www.codechef.com/problems/CBARG

#include<stdio.h>
int main()
{
	long long int t,n,m,previous,check;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		check=0;previous=0;
		while(n--)
		{
			scanf("%lld",&m);
			if(previous<m)
			{
				check+=(m-previous);
				//previous=m;
			}
			previous=m;
		}
		printf("%lld\n",check);
	}
}

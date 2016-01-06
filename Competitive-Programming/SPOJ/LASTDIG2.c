/*
http://www.spoj.com/problems/LASTDIG2/
Logic = a^b and (a%10)^b has same last digit
*/
#include<stdio.h>
#include<string.h>

int modularPow(long long int a,long long int b, char m)
{
	// return (a^b)%c
	long long int result=1;
	while(b!=0)
	{
		if(b&1)
		{
			// b is odd
			result=(result*a)%m;
		}
		a=(a*a)%m;
		b/=2;
	}
	return result;
}
int main()
{
	char a[1001];
	int t,last,i;
	long long int b,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		scanf("%lld",&b);
		last=a[strlen(a)-1]-48; // extracting the last digit
		res=modularPow(last,b,10);
		printf("%lld\n",res);
	}
	return 0;
}

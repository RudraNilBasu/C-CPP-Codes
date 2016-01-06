/*
https://www.codechef.com/problems/CKISSHUG
Answer = 2^(floor(N/2)) + 2^(ceil(n/2)) -2
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long 
#define MOD 1000000007
long long int power(long long int a,long long int n)
{
	// calculate a^n % MOD
	long long int result=1;
	while(n!=0)
	{
		if(n&1)
		{
			// if n is odd
			result=(result*a)%MOD;
		}
		a=(a*a)%MOD;
		n/=2;
	}
	return result;
}
int main()
{
	int t;
	long long int n,flr,cl,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		n++;
		flr=(n)/2; // floor value;
		cl=n-flr; // ceil value
		res=power(2,flr)+power(2,cl)-2;
		printf("%lld\n",(long long int)res%MOD);
	}
	return 0;
}
 

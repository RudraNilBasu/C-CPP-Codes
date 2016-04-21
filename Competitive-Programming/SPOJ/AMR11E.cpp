#include<stdio.h>
#include<math.h>
using namespace std;
int a[1001];
int seive[7920]; // 1000th prime no is 7919
int primes[7920];
int calc()
{
	int i,j,p=0;
	for(i=0;i<7920;i++)
	{
		seive[i]=0; // 0 meaning prime
	}
	seive[2]=0;
	for(i=2;i<7920;i++)
	{
		if(!a[i])
		{
			primes[p++]=i;
			// meaning i is prime
			// mark all multiples of i as not prime
			for(j=i+i;j<7920;j+=i)
			{
				a[j]=1; // marking as non prime
			}
		}
	}
	int k=2,n=43,no;
	a[0]=30;a[1]=42;
	while(k<1001)
	{
		no=0;
		for(i=0;i<1000;i++)
		{
			if(primes[i]>n) break;
			if(n%primes[i]==0)
			{
				no++;
				if(no>=3)
				{
					a[k++]=n;
					break;
				}
			}
		}
		n++;
	}
}
int main()
{
	calc();
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);printf("%d\n",a[n-1]);
		// print a[n-1]
	}
	return 0;
}

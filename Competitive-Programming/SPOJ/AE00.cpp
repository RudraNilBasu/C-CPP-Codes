#include<stdio.h>
#include<math.h>
using namespace std;
int a[10001];
int calculate(int n)
{
	// calculate the number of pairs of factors
	int i,fact=0,range=(int)n/2;
	float sq=sqrt(n);
	for(i=1;i<=(int)sq;i++)
	{
		if(n%i==0)
			fact++;
	}
	return fact;
}
int main()
{
	a[0]=0;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i]=calculate(i)+a[i-1];
	}
	printf("%d\n",a[n]);
	return 0;
}

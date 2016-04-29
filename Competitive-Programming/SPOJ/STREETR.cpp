#include<stdio.h>
using namespace std;
int hcf(int a, int b)
{
	if(a==0) return b;
	return hcf(b%a,a);
}
int main()
{
	int n,i,k;
	scanf("%d",&n);
	int a[n];
	int b[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(i>0) 
		{
			b[i]=a[i]-a[i-1];
		}
		if(i==1) 
		{
			k=a[1]-a[0];
		}
		else if(i>1)
		{
			k=hcf(k,a[i]-a[0]);
			b[i]=a[i]-a[i-1];
		}
	}
	if(n>1)
	{
		int count=0;
		for(i=1;i<n;i++) count+=(b[i]/k)-1;
		printf("%d\n",count);
	}
	else
	{
		printf("0\n");
	}
	return 0;
}

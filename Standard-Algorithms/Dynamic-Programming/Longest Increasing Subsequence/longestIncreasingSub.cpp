#include<stdio.h>
using namespace std;
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n];
	int lis[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		lis[i]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i] && lis[j]+1 > lis[i])
				lis[i]=lis[j]+1;
		}
	}
	// finding the maximum value
	int max=-1;
	for(i=0;i<n;i++)
	{
		if(lis[i]>max)
			max=lis[i];
	}
	printf("The longest increasing subsequence is %d\n",max);
	return 0;
}

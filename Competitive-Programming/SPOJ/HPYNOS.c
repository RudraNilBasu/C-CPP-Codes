/*
http://www.spoj.com/problems/HPYNOS/
Find the sum of squares of each number. Check if it is already present in the array a[]
if it is present, then we are covering a cycle, hence the output should be -1
If not, add the value to the array
*/

#include<stdio.h>
int dissect(int n)
{
	int sum=0;
	while(n)
	{
		int temp=n%10;
		sum+=(temp*temp);
		n/=10;
	}
	return sum;
}
int main()
{
	int a[1000]={0};
	int n,c=0,hit=1;
	scanf("%d",&n);
	while(1)
	{
		int temp=dissect(n);
		c++;
		if(a[temp]==0)
		{
			a[temp]=1;
			n=temp;
		}
		else
		{
			hit=0;
			break;
		}
		if(n==1)
		{
			break;
		}
	}
	if(hit)
	{
		printf("%d\n",c);
	}
	else
	{
		printf("-1\n");
	}
}

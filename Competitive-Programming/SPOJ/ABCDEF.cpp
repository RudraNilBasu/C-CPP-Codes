//http://www.spoj.com/problems/ABCDEF/
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int i,n,j,k;
	int a[101];
	vector<int>lhs;
	vector<int>rhs;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				lhs.push_back(a[i]*a[j]+a[k]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(a[k]==0) continue;
				rhs.push_back(a[k]*(a[j]+a[i]));
			}
		}
	}
	// sorting
	sort(lhs.begin(),lhs.end());
	sort(rhs.begin(),rhs.end());
	// calculating result
	long long int res=0;
	for(i=0;i<lhs.size();i++)
	{
		int lo=lower_bound(rhs.begin(),rhs.end(),lhs[i])-rhs.begin();
		int hi=upper_bound(rhs.begin(),rhs.end(),lhs[i])-rhs.begin();
		res+=(hi-lo);
	}
	printf("%lld\n",res);
	return 0;
}

#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,k,j,ans;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		int a[2000];
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		ans=0;
		for(i=0;i<n-2;i++)
		{
			for(j=i+1;j<n-1;j++)
			{
				// search x > a[i]+a[j]
				int low=j+1,high=n-1,mid=(low+high)/2;
				while(low<high)
				{
					mid=(low+high)/2;
					if(low==high) break;
					if(a[mid]==(a[i]+a[j]))
					{
						low=mid+1;
					}
					else if(a[mid]<(a[i]+a[j]))
					{
						low=mid+1;
					}
					else if(a[mid]>(a[i]+a[j]))
					{
						high=mid;
					}
				}
				mid=(low+high)/2;
				if(a[mid]>(a[i]+a[j]))
				{
					ans+=(n-mid);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

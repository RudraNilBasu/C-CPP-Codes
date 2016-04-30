#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	while(1)
	{
		int n,i;
		int currFuel=0,currPos=0,round=0;
		scanf("%d",&n);
		if(n==0) break;
		int a[n];
		int hash[1423];
		memset(hash,-1,sizeof(hash));
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			hash[a[i]]=1;
		}
		sort(a,a+n);
		currFuel=0,currPos=0,round=0;
		if(a[0]==0) currFuel=200;
		while(currFuel>0)
		{
			if(round==0)
			{
				currPos++;
				currFuel--;
				if(currPos==1422) round=1;
			}
			else
			{
				currPos--;
				currFuel--;
				if(currPos==0) break;
			}

			if(hash[currPos]==1) currFuel+=200;
			if(currFuel>200) currFuel=200;
		}
		if(currPos==0 && round==1)
		{
			printf("POSSIBLE\n");
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}

#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int maxProd=-1,index;
		int l[n],r[n],prod[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&l[i]);
		}
		for(i=0;i<n;i++)
			scanf("%d",&r[i]);
		for(i=0;i<n;i++)
		{
			prod[i]=l[i]*r[i];
			if(prod[i]>maxProd)
			{
				maxProd=prod[i];
				index=i;
			}
			else if(prod[i]==maxProd)
			{
				if(r[i]>r[index])
				{
					index=i;
					maxProd=prod[i];
				}
				/*
				else if(r[i]==r[index])
				{
				}
				*/
			}
		}
		printf("%d\n",(index+1));
	}
	return 0;
}

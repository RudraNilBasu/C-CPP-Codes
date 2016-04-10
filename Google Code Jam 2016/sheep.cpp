#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i,r,test,mult,found,numb;
	int a[10];
	scanf("%d",&t);
	for(test=1;test<=t;test++)
	{
		scanf("%d",&n);
		found=0;
		if(n==0)
		{
			printf("Case #%d: INSOMNIA\n",test);
			continue;
		}
		// marking all as unseen
		for(i=0;i<10;i++) a[i]=-1;
		mult=1;
		while(!found)
		{
			numb=mult*n;
			r=numb;
			while(r>0)
			{
				int last=r%10;
				r/=10;
				a[last]++;
			}
			int flag=0;
			for(i=0;i<10;i++)
			{
				if(a[i]==-1)
				{
					flag=1;
				}
			}
			if(!flag)
			{
				printf("Case #%d: %d\n",test,numb);
				found=1;
				//break;
			}
			mult++;
		}
	}
	return 0;
}

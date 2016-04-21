#include<stdio.h>
#include<algorithm>
using namespace std;
char pos[10000001];
int a[10000001];
int main()
{
	//char pos[1000]; // array to remember whether a time is entry or exit (left or right)
	//int a[1000];
	int t,n,i,st,end,k,count,max;
	scanf("%d",&t);
	while(t--)
	{
		k=0;
		count=0;
		max=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&st,&end);
			pos[st]='l';
			pos[end]='r';
			a[k++]=st;
			a[k++]=end;
		}
		sort(a,a+k);
		for(i=0;i<k;i++)
		{
			if(pos[a[i]]=='l')
			{
				count++;
			}
			else if(pos[a[i]]=='r')
			{
				count--;
			}
			// check if max or min
			if(count>max) max=count;
		}
		printf("%d\n",max);
	}
	return 0;
}

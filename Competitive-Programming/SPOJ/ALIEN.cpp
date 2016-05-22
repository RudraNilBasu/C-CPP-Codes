#include<stdio.h>
#define ll long long int
using namespace std;
int main()
{
	int t,at,i;
	ll bt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %lld",&at,&bt);
		int a[at];
		for(i=0;i<at;i++)
			scanf("%d",&a[i]);
		ll max=0,sum=0;
		int stations=0,first=0,maxStations=0;
		for(i=0;i<at;i++)
		{
			while((sum+a[i])>bt)
			{
				if(stations>maxStations)
				{
					maxStations=stations;
					max=sum;
				}
				else if(stations==maxStations)
				{
					max=(sum<max)?sum:max;
				}
				sum-=a[first++];
				stations--;
			}
			sum+=a[i];
			stations++;
		}
		if(stations>maxStations)
		{
			maxStations=stations;
			max=sum;
		}
		printf("%lld %d\n",max,maxStations);
	}
	return 0;
}

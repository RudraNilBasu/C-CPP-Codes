/*
 Link - https://books.google.co.uk/books?id=N8WtPdzu-MsC&pg=RA1-PA113&lpg=RA1-PA113&dq=inverting+a+coin+triangle&source=bl&ots=7Z9i2UYHam&sig=weB1pgbNMdalS_mu5JuF5tWwEiY&hl=en&sa=X&ei=uO8AVMqeLorT7Aa2tICIBA#v=onepage&q=inverting%20a%20coin%20triangle&f=false
 */
#include<stdio.h>
using namespace std;
#define ll unsigned long long int
int main()
{
	int n;
	ll h;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%llu",&h);
		if(h==0 || h==1)
		{
			printf("0\n");
			continue;
		}
		ll ans=(h*(h+1))/6;
		printf("%llu\n",ans);
	}
	return 0;
}

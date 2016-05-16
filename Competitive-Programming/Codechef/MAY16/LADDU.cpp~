#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,act,laddu,rank,redeem,ans;
	char nat[11]; // nationality
	char activity[20]; // activity
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&act); // no of activities
		scanf("%s",nat);
		ans=0;
		if(strcmp(nat,"INDIAN")==0)
			redeem=200;
		else if(strcmp(nat,"NON_INDIAN")==0)
			redeem=400;
		laddu=0; // no of laddus
		while(act--)
		{
			scanf("%s",activity);
			if(strcmp(activity,"CONTEST_WON")==0)
			{
				scanf("%d",&rank);
				laddu+=300;
				if(rank<=20)
					laddu+=(20-rank);
			}
			else if(strcmp(activity,"TOP_CONTRIBUTOR")==0)
				laddu+=300;
			else if(strcmp(activity,"BUG_FOUND")==0)
			{
				scanf("%d",&rank); // here rank denotes the severity
				laddu+=rank;
			}
			else if(strcmp(activity,"CONTEST_HOSTED")==0)
				laddu+=50;
		}
		while(laddu>=redeem)
		{
			laddu-=redeem;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

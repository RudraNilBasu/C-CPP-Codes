#include<stdio.h>
#include<algorithm>
using namespace std;
struct activity{
	int start;
	int end;
};
bool srt(struct activity a, struct activity b)
{
	if(a.end==b.end)
	return a.start<b.start;
	return a.end<b.end;
}
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		struct activity act_list[n];
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&act_list[i].start,&act_list[i].end);
		}
		sort(act_list,act_list+n,srt);
		int prev_end=-1,count=0;
		for(i=0;i<n;i++)
		{
			if(act_list[i].start>=prev_end)
			{
				count++;
				prev_end=act_list[i].end;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

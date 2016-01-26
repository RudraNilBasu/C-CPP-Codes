//http://www.spoj.com/problems/PIGBANK/
#include<stdio.h>
#include<limits.h>
#include<string.h>
using namespace std;
int val[500];
int wt[500];
int main()
{
    int t,e,f,n,p,w,W,i,j,totalCoins;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&e,&f);
        W=f-e;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&val[i],&wt[i]);
        }
        int *ans = new int[f-e+1];
        memset(ans,-1,sizeof(ans));
        totalCoins=0;
        ans[0]=0;
        for(i=1;i<(f-e+1);i++)
        {
            ans[i]=-1;
            // iterating over the weight of each coin
            for(j=0;j<n;j++)
            {
                if((wt[j]<=i) && ans[i-wt[j]]!=-1 && (ans[i]==-1 || val[j]+ans[i-wt[j]]<ans[i]))
                {
                    ans[i]=val[j]+ans[i-wt[j]];
                }
            }
        }
        if(ans[f-e]!=-1)
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",ans[f-e]);
        }
        else
        {
            printf("This is impossible.\n");
        }
    }
    return 0;
}

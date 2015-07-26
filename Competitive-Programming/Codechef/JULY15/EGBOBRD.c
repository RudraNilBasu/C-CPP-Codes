//https://www.codechef.com/JULY15/problems/EGBOBRD
//https://www.codechef.com/problems/EGBOBRD

#include<stdio.h>
 
#define ll long long
#define FOR(i,a,x) for(i=a;i<x;i++)
 
int main()
{
    ll T,perday[100001],N,K,left,diff,packPerDay,total,j,i;
    scanf("%lld",&T);
    for(j=1;j<=T;j++)
    {
        scanf("%lld %lld",&N,&K);//
        for(i=0;i<N;i++)
        {
            scanf("%lld",&perday[i]);
        }
        packPerDay=0;total=0;diff=0;left=0;
        FOR(i,0,N)//Run through all the days
        {
            diff=perday[i]-left;
            packPerDay=0;
            if(diff>0)
            {
                left=0;
            }
            else if(diff <= 0)
            {
                diff=0;
                left = left - perday[i];
            }
            //printf("diff = %lld",diff);
            packPerDay=diff/K;
            if(diff % K !=0)
            {
                packPerDay++;
            }
            if(diff>0)
            {
                left = (packPerDay*K) - diff;
            }
            if(left!=0)
            {
                left--;
            }
            total = total + packPerDay;
        }
        printf("%lld\n",total);
    }
    return 0;
}

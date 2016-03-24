//http://www.spoj.com/problems/NY10E/
#include<stdio.h>
#define ll long long int
using namespace std;
int main()
{
    int p,no,n,k,i,j;
    ll dp[66][10];   // of the form [no of digits][last digit]
    for(i=1;i<=65;i++)
    {
        for(j=0;j<10;j++)
        {
            if(i==1)
            {
                dp[i][j]=1;
            }
            else
            {
                ll sum=0;
                for(k=j;k>=0;k--)
                {
                    sum+=dp[i-1][k];
                }
                dp[i][j]=sum;
            }
        }
    }
    scanf("%d",&p);
    while(p--)
    {
        scanf("%d %d",&no,&n);
        printf("%d %lld\n",no,dp[n+1][9]);
    }
    return 0;
}

//http://www.spoj.com/problems/FAVDICE/
/*
Coupon collector's problem
ans = n*(1+1/2+1/3.....1/n)
*/
#include<stdio.h>
using namespace std;
float dice(int n)
{
    int i=0;
    float ans=0;
    for(i=1;i<=n;i++)
    {
        ans+=(1.0/(i*1.0));
    }
    ans*=n;
    return ans;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%.2f\n",dice(n));
    }
    return 0;
}

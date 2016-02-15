//http://www.spoj.com/problems/ALICESIE/
#include<stdio.h>
#define sd(n) scanf("%d",&n)
using namespace std;
int main()
{
    int t,i,n,k,ans;
    sd(t);
    while(t--)
    {
        sd(n);
        if(n&1)
        {
            printf("%d\n",(n+1)/2);
        }
        else
        {
            printf("%d\n",n/2);
        }
    }
    return 0;
}

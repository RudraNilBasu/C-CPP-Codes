//http://www.spoj.com/problems/TRGRID/
#include<stdio.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m,i,j;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        if(n<=m)
        {
            if(n&1)
            {
                printf("R\n");
            }
            else
            {
                printf("L\n");
            }
        }
        else if(n>m)
        {
            if((m)&1)
            {
                printf("D\n");
            }
            else
            {
                printf("U\n");
            }
        }
    }
    return 0;
}

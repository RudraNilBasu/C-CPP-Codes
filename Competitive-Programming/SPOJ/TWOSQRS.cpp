//http://www.spoj.com/problems/TWOSQRS/
#include<stdio.h>
#include<math.h>
using namespace std;
int isPerfectSquare(long long int n)
{
    long long int t=sqrt(n);
    if((t*t)==n) return 1;
    return 0;
}
int main()
{
    int c;
    scanf("%d",&c);
    while(c--)
    {
        long long int n,i;
        int flag=0;
        scanf("%lld",&n);
        for(i=0;(i*i)<=n;i++)
        {
            if(isPerfectSquare(n-(i*i)))
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

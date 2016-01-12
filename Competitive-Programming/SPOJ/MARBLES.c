//http://www.spoj.com/problems/MARBLES/

#include<stdio.h>
 
 
long long int multinomial(long n,long r)
{
    long long int i,ans;
    if(r==n)
    {
        return 1;
    }
    else
    {
        if(r>n/2)
        {
            r=n-r;
        }
        ans=1;
        for(i=1;i<=r;i++)
        {
            ans*=(n-r+i);
            ans/=i;
        }
        return ans;
    }
}
int main()
{
    int t;
    long k,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&k);
        printf("%lld\n",multinomial(n-1,k-1));
    }
    return 0;
}

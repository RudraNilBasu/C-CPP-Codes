//http://www.spoj.com/problems/RPLC/
#include<stdio.h>
#define sclld(x) scanf("%lld",&x)
#define ll long long int
using namespace std;
ll ab(ll n)
{
    if(n<0)
    return n*-1;
    return n;
}
int main()
{
    ll t,n,i,x,sum,energy,j;
    sclld(t);
    for(j=1;j<=t;j++)
    {
        sclld(n);
        x=1; // the abount of energy to take in the beginning
        sum=x; //sum of all energies upto a certain point
        for(i=0;i<n;i++)
        {
            sclld(energy); // individual energy value
            sum+=energy;
            if(sum<=0)
            {
                x+=(1+ab(sum));
                sum=1;
            }
        }
        printf("Scenario #%lld: %lld\n\n",j,x);
    }
    return 0;
}

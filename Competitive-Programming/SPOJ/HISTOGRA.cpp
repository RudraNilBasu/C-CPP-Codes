//http://www.spoj.com/problems/HISTOGRA/
/*
http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
*/
#include<stdio.h>
#include<stack>
using namespace std;
#define ll long long int
ll maxArea(ll h[], ll n)
{
    stack<ll> s;
    ll i=0;
    ll ans_max=0,ans_tp=0;
    while(i<n)
    {
        if(s.empty() || h[s.top()]<=h[i])
        {
            s.push(i++);
        }
        else
        {
            ll tp=s.top();
            s.pop();
            ans_tp=h[tp]*(s.empty() ? i:i-s.top()-1);
            if(ans_tp>ans_max)
            {
                ans_max=ans_tp;
            }
        }
    }
    while(!s.empty())
    {
        ll tp=s.top();
        s.pop();
        ans_tp=h[tp]*(s.empty() ? i:i-s.top()-1);
        if(ans_tp>ans_max)
        {
            ans_max=ans_tp;
        }
    }
    return ans_max;
}
int main()
{
    ll n,i;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0) break;
        ll ht[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ht[i]);
        }
        printf("%lld\n",maxArea(ht,n));
    }
    return 0;
}

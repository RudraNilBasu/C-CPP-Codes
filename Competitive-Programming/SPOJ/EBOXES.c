//http://www.spoj.com/problems/EBOXES/
/*
Explanation (from the test cases in SPOJ)
11 large boxes
n filled

8*n medium boxes
m filled

8*m smaller boxes

Total no of empty boxes
(11-n)+(8*n - m) + 8*m

11 - n + 8*(n+m) - m
11 - (n+m) + 8*(n+m) = 102
11 + 7*(n+m) = 102
(n+m) = (102-11)/7
(n+m) = 13

Total no of boxes on the table = 11 + 8*n + 8*m = 11 + 8*(n+m)
=11 + 8*13


---------
(n+m) = (102-11)/(8-1)
ans = 11 + 8 * (n+m)
---------
Here n+m is represented as sum
*/
#include<stdio.h>
#define ll long long int
int main()
{
    ll N,K,T,F,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&N,&K,&T,&F);
        ll sum = (F-N)/(K-1); // total sum of the number of filled large and medium boxes
        ll ans = N+(K*sum);
        printf("%lld\n",ans);
    }
    return 0;
}

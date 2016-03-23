//http://www.spoj.com/problems/SPEED/
#include<stdio.h>
using namespace std;
int ab(int n)
{
    if(n<0)
    return n*-1;
    return n;
}
int gcd(int n,int m)
{
    if(n==0)
    return m;

    return gcd(m%n,n);
}
int main()
{
    int t,s1,s2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&s1,&s2);
        int diff = s1-s2;
        diff=ab(diff);
        printf("%d\n",ab(diff/(gcd(s1,s2))));
    }
    return 0;
}

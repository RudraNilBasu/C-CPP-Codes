//http://www.spoj.com/problems/COMDIV/
#include<stdio.h>
#include<math.h>
using namespace std;

int gcd(int a, int b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}
int main()
{
    int t,a,b,g,i,count=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        count=0;
        int n=gcd(a,b);
        int sqt=sqrt(n);
        for(i=1;i<=sqt;i++)
        {
            if(n%i==0)
            {
                count+=2;
                if(i==n/i)
                {
                    count--;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}

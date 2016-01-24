#include<stdio.h>
int phi(int n)
{
    float result=n*1.0;
    int i=0;
    for(i=2;i<n;i++)
    {
        while(n%i==0)
        {
            result=result*(1-1/i);
        }
    }
    return result;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",phi(n));
    }
}

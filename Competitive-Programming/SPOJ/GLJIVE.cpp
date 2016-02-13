//http://www.spoj.com/problems/GLJIVE/
#include<stdio.h>
using namespace std;
int absdiff(int n)
{
    n=n-100;
    if(n>=0)
    return n;
    return (-1*n);
}
int main()
{
    int a[10];
    int i,count=0,currdiff=100;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    count=0;
    for(i=0;i<10;i++)
    {
        if(absdiff(a[i]+count)<=currdiff)
        {
            currdiff=absdiff(a[i]+count);
            count+=a[i];
        }
        else
        {
            break;
        }
    }
    printf("%d\n",count);
    return 0;
}

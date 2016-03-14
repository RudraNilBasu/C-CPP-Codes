//http://www.spoj.com/problems/HACKRNDM/
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int bsearch(int x, int *a)
{
    // returns the number of occurance of x in a[]
    int low=0,high=n-1,mid,c=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==x)
        {
            c++;
            // check if same item is before and after the number
            int nxt=mid+1;
            while(a[nxt]==x)
            {
                nxt++;
                c++;
            }
            int prv=mid-1;
            while(a[prv]==x)
            {
                c++;
                prv--;
            }
            return c;
        }
        else if(a[mid]<x)
        {
            low=mid+1;
        }
        else if (a[mid]>x)
        {
            high=mid-1;
        }
    }
    return 0;
}
int main()
{
    int k,i,count=0;
    scanf("%d %d",&n,&k);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    sort(a,a+n);

    for(i=0;i<n;i++)
    {
        int x=a[i];
        if((x+k)<=a[n-1])
        {
            count+=bsearch(x+k,a); // bsearch will return the number of occurance of x+2
        }
    }
    printf("%d\n",count);
    return 0;
}

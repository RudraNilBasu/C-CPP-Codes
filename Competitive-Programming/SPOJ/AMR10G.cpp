#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int main()
{
    int t;
    int n,k,i,min=0;;
    int *a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        a=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        //Sorting in ascending order
        sort(a,a+n);
        //Checking
        min=INT_MAX;
        for(i=0;i+k-1<n;i++)
        {
            int sum=a[i+k-1]-a[i];
            if(min>sum)
            {
                min=sum;
            }
        }
        printf("%d\n",min);
    }
    return 0;
}

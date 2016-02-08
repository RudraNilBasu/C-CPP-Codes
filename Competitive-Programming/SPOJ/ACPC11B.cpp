//http://www.spoj.com/problems/ACPC11B/
#include<stdio.h>
#include<limits.h>
using namespace std;
int main()
{
    int t,n,m,i,j,min;
    int a[1001],b[1001];
    scanf("%d",&t);
    while(t--)
    {
        min=INT_MAX;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int diff=a[i]-b[j];
                if(diff<0)
                {
                    diff*=-1;
                }
                if(min>diff)
                {
                    min=diff;
                }
            }
        }
        printf("%d\n",min);
    }
    return 0;
}

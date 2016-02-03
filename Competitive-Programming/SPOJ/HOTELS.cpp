//http://www.spoj.com/problems/HOTELS/
#include<stdio.h>
#define ll long long
using namespace std;
int main()
{
    int n,i,m,j;
    ll int max_so_far=0,max_ends_here=0;
    int a[300000];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    i=0;
    j=0;
    for(i=0;i<n;i++)
    {
        max_ends_here+=a[i];
        if(max_ends_here==m)
        {
            max_so_far=max_ends_here;
            break;
        }
        else if(max_ends_here>m)
        {
            while(max_ends_here>m)
            {
                max_ends_here-=a[j++];
            }
        }
        if( max_ends_here > max_so_far )
        {
            max_so_far=max_ends_here;
        }
    }
    printf("%lld\n",max_so_far);
    return 0;
}

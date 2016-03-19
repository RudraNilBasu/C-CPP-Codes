//http://www.spoj.com/problems/FASHION/
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int men[n],women[n];
        for(i=0;i<n;i++)
        scanf("%d",&men[i]);
        for(i=0;i<n;i++)
        scanf("%d",&women[i]);
        sort(men,men+n);
        sort(women,women+n);
        int sum=0;
        for(i=0;i<n;i++)
        sum+=men[i]*women[i];
        printf("%d\n",sum);
    }
    return 0;
}

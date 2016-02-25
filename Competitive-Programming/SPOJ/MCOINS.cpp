//http://www.spoj.com/problems/MCOINS/
//https://www.topcoder.com/community/data-science/data-science-tutorials/algorithm-games/
#include<stdio.h>
using namespace std;
#define ll long long int
#define MAX 1000005
ll k,l;
int main()
{
    ll m,n,i,j;
    scanf("%lld %lld %lld",&k,&l,&m);
    bool g[MAX];
    for(i=0;i<MAX;i++)
    {
        g[i]=false;
        if(i-1>=0 && g[i-1]==false) g[i]=true;
        if(i-k>=0 && g[i-k]==false) g[i]=true;
        if(i-l>=0 && g[i-l]==false) g[i]=true;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&n);
        if(g[n])
        {
            printf("A");
        }
        else
        {
            printf("B");
        }
    }
    printf("\n");
    return 0;
}

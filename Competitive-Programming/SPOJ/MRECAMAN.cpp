//http://www.spoj.com/problems/MRECAMAN/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<map>
#define ll long long int
using namespace std;
int range=500000;
ll a[500000];
int main()
{
    int k,i;
    map<ll,int> hash;
    a[0]=0;
    for(i=1;i<=range;i++)
    {
        a[i]=a[i-1]-i;
        if(a[i]<=0 || hash[a[i]])
        {
            a[i]=a[i-1]+i;
        }
        hash[a[i]]=1;
    }
    while(1)
    {
        scanf("%d",&k);
        if(k==-1)
        break;
        printf("%lld\n",a[k]);
    }
    return 0;
}

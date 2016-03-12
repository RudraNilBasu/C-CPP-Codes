//http://www.spoj.com/problems/PERMUT1/
#include<stdio.h>
int a[99][99];
using namespace std;
int comp()
{
    int n,k,j;
    for(n=0;n<=99;n++)
    {
        a[n][0]=0;
    }
    a[1][0]=1;
    a[1][1]=0;
    for(n=2;n<=12;n++)
    {
        for(k=0;k<=98;k++)
        {
            if(k==0)
            {
                a[n][k]=1;
                continue;
            }
            int x=0;
            for(j=0;j<n && k-j>=0;j++)
            {
                x+=a[n-1][k-j];
            }
            a[n][k]=x;
        }
    }
}
int main()
{
    int d,n,k;
    scanf("%d",&d);
    comp();
    while(d--)
    {
        scanf("%d %d",&n,&k);
        printf("%d\n",a[n][k]);
    }
    return 0;
}

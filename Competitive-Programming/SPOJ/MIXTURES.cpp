//http://www.spoj.com/problems/MIXTURES/
// Matrix Chain Multiplication - http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
#include<stdio.h>
#define INF 2143483647
using namespace std;
int a[100];
int memo[100][100];
int n;
int csum(int i,int j)
{
    int k,sum=0;
    for(k=i;k<=j;k++)
    {
        sum=(sum+a[k])%100;
    }
    return sum;
}
int mix(int i, int j)
{
    if(memo[i][j]!=INF)
    {
        return memo[i][j];
    }
    if(i==j)
    {
        return memo[i][j]=0;
    }
    else
    {
        int k=0,q=0;
        for(k=i;k<j;k++)  // traversing through the given range and finding all combinations
        {
            q=mix(i,k)+mix(k+1,j) + csum(i,k)*csum(k+1,j);
            if(q<memo[i][j])
            {
                memo[i][j]=q;
            }
        }
        return memo[i][j];
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int i,j;
        for(i=0;i<100;i++)
        {
            for(j=0;j<100;j++)
            {
                memo[i][j]=INF;
            }
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        printf("%d\n",mix(0,n-1));
    }
    return 0;
}

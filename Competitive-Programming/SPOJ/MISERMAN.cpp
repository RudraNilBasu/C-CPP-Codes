//http://www.spoj.com/problems/MISERMAN/
#include<stdio.h>
#include<limits.h>
using namespace std;
int a[100][100];
int dp[100][100];
int n,m;
int min3(int a, int b, int c)
{
    if(a<=b && a<=c)
    return a;
    if(b<=a && b<=c)
    return b;
    return c;
}
int min2(int a, int b)
{
    if(a<b)
    return a;
    return b;
}
int calc(int i, int j)
{
    // Find min dist for i,j th position
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    // if it is in the first row
    if(i==0)
    {
        return dp[i][j]=a[i][j];
    }

    // if the element is in the leftmost corner
    if(j==0)
    {
        return dp[i][j]=a[i][j]+ min2(
                                     calc(i-1,j),
                                     calc(i-1,j+1)
                                     );
    }
    // if the element is in the rightmost element
    if(j==m-1)
    {
        return dp[i][j]=a[i][j]+ min2(
                                      calc(i-1,j),
                                      calc(i-1,j-1)
                                      );
    }
    // if element is in mid-way
    return dp[i][j]=a[i][j]+min3(
                                 calc(i-1,j),
                                 calc(i-1,j-1),
                                 calc(i-1,j+1)
                                 );
}
int main()
{
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(j=0;j<m;j++)
    {
        calc(n-1,j);
    }
    int min=INT_MAX;
    for(j=0;j<m;j++)
    {
        if(min>dp[n-1][j])
        {
            min=dp[n-1][j];
        }
    }
    printf("%d\n",min);
    return 0;
}

//http://www.spoj.com/problems/ACPC10D/
#include<stdio.h>
#include<limits.h>
using namespace std;
int a[1000000][3];
int dp[1000000][3];
int n;
int min(int a, int b)
{
    if(a<b)
    return a;
    return b;
}
int min3(int a, int b, int c)
{
    return min(min(a,b),c);
}
int min4(int a, int b, int c, int d)
{
    return min(min(a,b),min(c,d));
}
int calc(int i,int j)
{
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    // Base case
    if(i==n-1 && j==1)
    {
        return dp[i][j]=a[i][j];
    }
    // If we are in the last row
    if(i==(n-1) && j==0)
    {
        return dp[i][j]=a[i][j]+calc(i,j+1);
    }
    if(i==(n-1) && j==2)
    {
        //return dp[i][j]=a[i][j]+calc(i,j-1);
        return dp[i][j]=INT_MAX;
    }
    // General case
    if(j==0)
    {
        // leftmost part
        return dp[i][j]=a[i][j]+min3(
                           calc(i+1,j),
                           calc(i,j+1),
                           calc(i+1,j+1)
                           );
    }
    else if(j==1)
    {
        // middle
        return dp[i][j]=a[i][j]+min4(
                           calc(i+1,j),
                           calc(i,j+1),
                           calc(i+1,j+1),
                            calc(i+1,j-1)
                           );
    }
    else if(j==2)
    {
        // rightmost
        return dp[i][j]=a[i][j]+min(
                            calc(i+1,j),
                            calc(i+1,j-1)
                            );
    }
}
int main()
{
    int i,j,c=0;
    scanf("%d",&n);
    while(n!=0)
    {
        c++;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                scanf("%d",&a[i][j]);
                dp[i][j]=-1;
            }
        }
        printf("%d. %d\n",c,calc(0,1));
        scanf("%d",&n);
    }
    return 0;
}

/*
http://www.spoj.com/problems/TRT/
Best Explanation - https://www.quora.com/Are-there-any-good-resources-or-tutorials-for-dynamic-programming-besides-the-TopCoder-tutorial/answer/Michal-Danil%C3%A1k
*/
#include<stdio.h>
using namespace std;
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int a[2000];
int n;
int memo[2000][2000];
int profit(int beg,int end)
{
    // base case if no more foods are left
    if(beg>end)
    {
        return 0;
    }
    // checking if it is already present in the memo[][] or not
    if(memo[beg][end]!=-1)
    {
        return memo[beg][end];
    }
    int days=n-(end-beg+1)+1;
    return memo[beg][end]=max(
                               profit(beg+1,end)+(a[beg]*days),
                               profit(beg,end-1)+(a[end]*days)
                               );
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    // initialising memo to -1
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            memo[i][j]=-1;
        }
    }
    printf("%d\n",profit(0,n-1));
    return 0;
}

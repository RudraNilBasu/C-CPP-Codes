//http://www.spoj.com/problems/AIBOHP/
/*
Ans = Length of string - LPS of string
*/
#include<stdio.h>
#include<string.h>
using namespace std;
int L[6101][6101];
int MAX(int a, int b)
{
    return (a > b)? a : b;
}
int lps(char seq[], int n)
{
    int i,j,cl;
    for(i=0;i<n;i++)
    {
        L[i][i]=1;
    }
    for(cl=2;cl<=n;cl++)
    {
        for(i=0;i<n-(cl-1);i++)
        {
            j=i+(cl-1);
            if(seq[i]==seq[j] && cl!=2)
            {
                L[i][j]=2+L[i+1][j-1];
            }
            else if(seq[i]==seq[j] && cl==2)
            {
                L[i][j]=2;
            }
            else
            {
                // 1st and last element are not equal
                L[i][j]=MAX(
                            L[i+1][j],
                            L[i][j-1]
                            );
            }
        }
    }
    return L[0][n-1];
}
int main()
{
    int t,len;
    char seq[6101];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",seq);
        len=strlen(seq);
        printf("%d\n",(len-lps(seq,len)));
    }
}

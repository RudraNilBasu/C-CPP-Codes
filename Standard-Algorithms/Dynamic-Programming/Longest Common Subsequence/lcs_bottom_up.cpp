#include<stdio.h>
#include<string.h>
int MAX(int a, int b)
{
    return (a > b)? a : b;
}
int lcs(char X[], char Y[], int m, int n)
{
    int L[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                L[i][j]=0;
            }
            else
            {
                if(X[i-1]==Y[j-1])
                {
                    L[i][j]=1+L[i-1][j-1];
                }
                else
                {
                    L[i][j]=MAX(
                                L[i][j-1],
                                L[i-1][j]
                                );
                }
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",L[i][j]);
        }
        printf("\n");
    }
    return L[m][n];
}
int main()
{
    char X[] = "AGGTAB";
      char Y[] = "GXTXAYB";

      int m = strlen(X);
      int n = strlen(Y);

      printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
    return 0;
}

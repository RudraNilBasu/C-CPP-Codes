#include<stdio.h>
#include<cstring>
using namespace std;
int MAX(int a, int b)
{
    if(a>b)
    return a;
    return b;
}
int lps(char seq[], int n)
{
    int L[n][n];
    int i,j,cl;
    for(i=0;i<n;i++)
    {
        L[i][i]=1;
    }
    for(cl=2;cl<=n;cl++)
    {
        for(i=0;i<n-(cl-1);i++)
        {
            j=i+cl-1; // considering the interval i to j
            if(seq[i]==seq[j] && cl==2)
            {
                L[i][j]=2;
            }
            else if(seq[i]==seq[j])
            {
                L[i][j]=L[i+1][j-1]+2;
            }
            else
            {
                // str[i]!=str[j]
                L[i][j]=MAX(L[i][j-1],L[i+1][j]);
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",L[i][j]);
        }
        printf("\n");
    }

    return L[0][n-1];
}
int main()
{
    char seq[]="BBABCBCAB";
    int n=strlen(seq);
    printf("LPS of the given string is %d\n",lps(seq,n));
}


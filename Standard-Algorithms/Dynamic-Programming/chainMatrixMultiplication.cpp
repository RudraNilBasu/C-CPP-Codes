/*
http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
Bottom Up DP Method
*/
#include<stdio.h>
#include<limits.h>
using namespace std;
int matrixChainOrder(int a[], int n)
{
    int m[n][n];
    int i,L,j,k;
    for(i=0;i<n;i++)
    {
        //multiplied by itself is 0
        m[i][i]=0;
    }
    for(L=2;L<n;L++)
    {
        for(i=1;i<n+L;i++)
        {
            j=i+L-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                int q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                }
            }
        }
    }
    return m[1][n-1];
}
int main()
{
    int a[]={1,2,3,4};
    int n=sizeof(a)/sizeof(a[0]);
    printf("Minimum number of multiplications is %d\n",matrixChainOrder(a,n));
}

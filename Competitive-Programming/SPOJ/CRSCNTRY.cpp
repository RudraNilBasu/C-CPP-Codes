//http://www.spoj.com/problems/CRSCNTRY/
#include<stdio.h>
using namespace std;
int n,m;
/*
n = size of agne's checkpoints
m = size of Toby's checkpoints for each call
*/
int max(int a, int b)
{
    if(a>=b)
    return a;
    return b;
}
int LCS(int agne[], int toby[])
{
    int L[n+1][m+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                L[i][j]=0;
            }

            else if(toby[j-1]==agne[i-1])
            {
                L[i][j]=1+L[i-1][j-1];
            }

            else
            {
                L[i][j]=max(L[i][j-1],L[i-1][j]);
            }
        }
    }

    return L[n][m];
}
int main()
{
    int d,i,maxd=0;
    scanf("%d",&d);
    while(d--)
    {
        int agne[2001];
        n=0;
        m=0;
        maxd=-1;
        for(i=0;i<2001;i++)
        {
            scanf("%d",&agne[i]);
            if(agne[i]==0)
            {
                break;
            }
            else
            {
                n++; // determine the size of the agne's checkpoints
            }
        }
        int toby[2001];
        while(1)
        {
            int x;
            scanf("%d",&x);
            if(x==0) break;
            else
            {
                toby[0]=x;
                m=1; // size of toby's checkpoints
                for(i=1;i<2001;i++)
                {
                    scanf("%d",&toby[i]);
                    if(toby[i]==0)
                    {
                        // call LCS and find max
                        maxd=max(LCS(agne,toby),maxd);
                        break;
                    }
                    else
                    {
                        m++;
                    }
                }
            }
        }
        printf("%d\n",maxd);
    }
    return 0;
}

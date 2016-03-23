//http://www.spoj.com/problems/CHOCOLA/
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int m,n,t,i,j,res,v,h;
    scanf("%d",&t);
    printf("\n");
    while(t--)
    {
        scanf("%d %d",&m,&n);
        int x[m],y[n]; // x = horizontal y = vertical
        for(i=1;i<m;i++)
        scanf("%d",&x[i]);
        sort(x+1,x+m);
        reverse(x+1,x+m);
        for(i=1;i<n;i++)
        scanf("%d",&y[i]);
        sort(y+1,y+n);
        reverse(y+1,y+n);

        i=1;
        j=1;
        res=0;
        v=1;
        h=1;

        while(i<m && j<n)
        {
            if(x[i]>y[j])
            {
                res=res+(x[i]*v);
                h++;
                i++;
            }
            else
            {
                res=res+(y[j]*h);
                v++;
                j++;
            }
        }
        while(i<m)
        {
            res+=x[i]*(v);
            i++;
            h++;
        }
        while(j<n)
        {
            res+=y[j]*(h);
            v++;
            j++;
        }
        printf("%d\n\n",res);
    }
    return 0;
}

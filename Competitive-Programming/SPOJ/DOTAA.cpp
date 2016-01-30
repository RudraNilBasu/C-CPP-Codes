//http://www.spoj.com/problems/DOTAA/
#include<stdio.h>
using namespace std;
int main()
{
    int t,D,n,m,H,k,flag=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&D);
        k=0;
        flag=0;
        while(n--)
        {
            scanf("%d",&H);
            while(H>D && flag==0)
            {
                H-=D;
                k++;
            }
            if(k>=m && flag==0)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("NO\n");
        }
        else if(flag==1)
        {
            printf("YES\n");
        }
    }
    return 0;
}

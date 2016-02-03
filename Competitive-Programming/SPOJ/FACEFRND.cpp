//http://www.spoj.com/problems/FACEFRND/
#include<stdio.h>
using namespace std;
int main()
{
    int n,m,id,i,t,count=0;
    int a[10000];
    for(i=0;i<10000;i++)
    {
        a[i]=-1;
    }
    scanf("%d",&n); // n= no of Bob's Friend
    while(n--)
    {
        scanf("%d",&id); // id of bob's friend
        a[id]=0; // 0 indicating Bob's friend
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&id);
            if(a[id]==-1) // if that id is not assigned
            {
                a[id]=1;
            }
        }
    }
    for(i=0;i<10000;i++)
    {
        if(a[i]!=0 && a[i]!=-1)
        count++;
    }
    printf("%d\n",count);
    return 0;
}

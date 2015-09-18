//https://www.codechef.com/problems/PERMUT2/

#include<stdio.h>
int main()
{
    long int n,i;
    int flag;
    scanf("%ld",&n);
    long int a[100002] = {0};
    while(n!=0)
    {
        flag=0;
        for(i=0;i<100002;i++)
        {
            a[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%ld",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(a[a[i]]!=i)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("not ambiguous\n");
        }
        else if(flag==0)
        {
            printf("ambiguous\n");
        }
        scanf("%ld",&n);
    }
    return 0;
}

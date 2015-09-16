//https://www.codechef.com/problems/BROKPHON/

#include<stdio.h>
int main()
{
    int t;
    long long int n,i,counter;
    long long int *a;
    long long int *b;
    scanf("%d",&t);
    while(t--)
    {
        counter=0;
        scanf("%lld",&n);
        a=(long long int*)malloc(n*sizeof(long long int));
        b=(long long int*)malloc(n*sizeof(long long int));
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            b[i]=0;   //the answer will be the number of 1s
        }
        for(i=0;i<n-1;i++)
        {
            if(a[i]!=a[i+1])
            {
                b[i]=1;
                b[i+1]=1;
            }
        }
        for(i=0;i<n;i++)
        {
            if(b[i]==1)
            {
                counter++;
            }
        }
        printf("%lld\n",counter);
    }
    return 0;
}

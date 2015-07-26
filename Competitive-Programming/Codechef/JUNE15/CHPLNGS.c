//https://www.codechef.com/JUNE15/problems/CHPLGNS
//https://www.codechef.com/problems/CHPLGNS

#include <stdlib.h>
#include<stdio.h>
long absolute(long x)
{
    return (x>0)?(x):(-x);
}
long part(long c[],long arr[],long s,long e)
{
    long i,j,pivot=arr[s];
    long t;
    i=s+1;
    for(j=s+1;j<=e;j++)
    {
        if(arr[j]<pivot)
        {
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
            c[i]=(c[i]+c[j])-(c[j]=c[i]);
            i++;
        }
    }
    t=0;
    t=arr[i-1];
    arr[i-1]=arr[s];
    arr[s]=t;
    c[i-1]=(c[i-1]+c[s])-(c[s]=c[i-1]);
    return (i-1);
}
 
int qusort(long c[],long arr[],long s,long e)
{
    if(s<e)
    {
        long pivot=part(c,arr,s,e);
        qusort(c,arr,s,pivot-1);
        qusort(c,arr,pivot+1,e);
    }
    return 0;
}
int main()
{
    long t,n,*m1,x,y,i,j,dist,*maxX,*c;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        m1=(long *)malloc(n*sizeof(long));
        maxX=(long *)malloc(n*sizeof(long));
        c=(long *)malloc(n*sizeof(long));
        for(i=0;i<n;i++)
        {
            scanf("%ld",&m1[i]);
            maxX[i]=0;
            for(j=0;j<m1[i];j++)
            {
                scanf("%ld %ld",&x,&y);
                if(maxX[i]<absolute(x))
                maxX[i]=absolute(x);
            }
        }
        for(i=0;i<n;i++)
        {
            c[i]=i;
        }
        qusort(c,maxX,0,n-1);
        for(i=0;i<n;i++)
        {
            maxX[i]=i;
        }
        qusort(maxX,c,0,n-1);
        for(i=0;i<n;i++)
        {
            printf("%ld ",maxX[i]);
        }
        printf("\n");
    }
    return 0;
}

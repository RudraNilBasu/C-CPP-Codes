#include <stdio.h>
#include <stdlib.h>
int quicksort(int[],int,int);
int partition(int[],int,int);
int main()
{
    int *a,n,i;
    printf("enter no. of element\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("the sorted array\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}
int quicksort(int a[],int start,int end)
{
    if(start<=end)
    {
        int pivotpoint=partition(a,start,end);
        quicksort(a,start,pivotpoint-1);
        quicksort(a,pivotpoint+1,end);
    }
    return 0;
}
int partition(int a[],int start,int end)
{
    int i,j,pivot=a[start];
    i=start+1;
    for(j=start+1;j<=end;j++)
    {
        if(a[j]<pivot)
        {
            a[j]=(a[j]+a[i])-(a[i]=a[j]);
            /*tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;*/
            i++;
        }
    }
    a[start]=(a[start]+a[i-1])-(a[i-1]=a[start]);
    /*tmp=a[i-1];
    a[i-1]=a[start];
    a[start]=tmp;*/
    return (i-1);
}

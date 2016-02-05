#include<stdio.h>
using namespace std;
int getSum(int BITree[], int index)
{
    int sum=0;
    index=index+1;
    while(index>0)
    {
        sum+=BITree[index];
        index -= index & (-index);
    }
    return sum;
}
int updateTree(int BITree[], int n, int index, int val)
{
    index=index+1;
    while(index<=n)
    {
        BITree[index]+=val;
        index += index & (-index);
    }
}
int *construct(int a[], int n)
{
    int *BITree=new int [n+1];
    // initialise to 0
    int i;
    for(i=1;i<n+1;i++)
    BITree[i]=0;
    // setting initial value as the index
    for(i=0;i<n;i++)
    {
        updateTree(BITree,n,i,a[i]);
    }
    return BITree;
}
int main()
{
    int a[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n=sizeof(a)/sizeof(a[0]);
    int *BITree=construct(a,n);
    printf("Sum of elements in arr[0..5] is %d\n",getSum(BITree,5));
    updateTree(BITree,n,3,6);
    printf("Sum of elements after update in arr[0..5] is %d\n",getSum(BITree,5));
    return 0;
}

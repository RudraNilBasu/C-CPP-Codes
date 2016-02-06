#include<stdio.h>
#define MAX 100
using namespace std;
int tree[MAX]={0};
int lazy[MAX]={0};
int updateRangeUtil(int si, int ss, int se, int us,int ue, int diff)
{
    if(lazy[si]!=0)
    {
        tree[si]+=(se-ss+1)*lazy[si];
        // if not leaf
        if(ss!=se)
        {
            tree[si*2+1]+=lazy[si];
            tree[si*2+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    if (ss>se || ss>ue || se<us)
        return 0;
    if(ss>=us&&se<=ue)
    {
        tree[si]+=(se-ss+1)*diff;
        if(ss!=se)
        {
            lazy[si*2+1]+=diff;
            lazy[si*2+2]+=diff;
        }
        return 0;
    }
    int mid = (ss+se)/2;
    tree[si]=updateRangeUtil(si*2+1,ss,mid,us,ue,diff)+updateRangeUtil(si*2+2,mid+1,se,us,ue,diff);
    return 0;
}
int updateRange(int n, int us, int ue, int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
int getSumUtil(int ss, int se, int qs, int qe,int si)
{
    if(lazy[si]!=0)
    {
        tree[si]+=(se-ss+1)*lazy[si];
        // if not leaf node
        if(ss!=se)
        {
            tree[si*2+1]+=lazy[si];
            tree[si*2+2]+=lazy[si];
        }
        lazy[si]=0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return tree[si];

    int mid = (ss + se)/2;
    return getSumUtil(ss,mid,qs,qe,si*2+1)+getSumUtil(mid+1,se,qs,qe,si*2+2);
}
int getSum(int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(0, n-1, qs, qe, 0);
}
int constructUtil(int a[], int ss, int se, int si)
{
    if (ss > se)
        return 0;
    if(ss==se)
    {
        tree[si]=a[ss];
        return 0;
    }
    int mid = (ss + se)/2;
    tree[si]=constructUtil(a,ss,mid,si*2+1)+constructUtil(a,mid+1,se,si*2+2);
    return 0;
}
int construct(int a[], int n)
{
    constructUtil(a,0,n-1,0);
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    construct(arr,n);
    printf("Sum from 1 to 3 is %d\n",getSum(n,1,3));
    // Add 10 to all nodes at indexes from 1 to 5.
    updateRange(n, 1, 5, 10);
    printf("Sum from 1 to 3 is %d\n",getSum(n,1,3));
    return 0;
}

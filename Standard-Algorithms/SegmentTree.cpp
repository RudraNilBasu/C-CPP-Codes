#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
int getMid(int s, int e) {  return s + (e -s)/2;  }
int getSumUTIL(int *st,int n,int ss,int se,int qs, int qe,int si)
{
    // if query range is out of the range
    if(qs<=ss && qe>=se)
    {
        return st[si];
    }
    if(se<qs||ss>qe)
    {
        return 0;
    }
    int mid=getMid(ss,se);
    return getSumUTIL(st,n,ss,mid,qs,qe,si*2+1)+getSumUTIL(st,n,mid+1,se,qs,qe,si*2+2);
}
int getSum(int *st,int n,int qs, int qe)
{
    if(qs<0 || qe>n-1 || qe<qs)
    {
        printf("Invalid Range\n");
        return -1;
    }
    return getSumUTIL(st,n,0,n-1,qs,qe,0);
}
int constructSTUTIL(int a[],int ss,int se,int *st,int si)
{
    //if only one element is there
    if(ss==se)
    {
        st[si]=a[ss];
        return a[ss];
    }
    int mid=getMid(ss,se);
    st[si]=constructSTUTIL(a,ss,mid,st,si*2+1)+constructSTUTIL(a,mid+1,se,st,si*2+2);
    return st[si];
}
int *constructST(int a[],int n)
{
    int ht=(int)(ceil(log2(n)));
    int max_size=2*(int)pow(2,ht)-1;
    int *st=new int[max_size];
    for(int i=0;i<max_size;i++){st[i]=0;}
    // Fillup of the allocated memory
    constructSTUTIL(a,0,n-1,st,0);
    return st;
}
int main()
{
    int a[]={1,3,5,7,9,11}; // segment array
    int n=sizeof(a)/sizeof(a[0]);
    int *st=constructST(a,n); // building the segment tree
    printf("Sum of range of index 1 to 3 is %d\n",getSum(st,n,1,3));
}

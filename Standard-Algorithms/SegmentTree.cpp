#include<stdio.h>
#include<math.h>
using namespace std;
int getMid(int s, int e) {  return s + (e -s)/2;  }
int getSum(int *st,int n,int qs, int qe)
{
    //
}
int constructSTUTIL(int a[],int ss,int se,int *st,int si)
{
    //if only one element is there
    if(ss==se)
    {
        st[si]=ss;
        return 0;
    }
    int mid=getMid(ss,se);
    st[si]=constructSTUTIL(a,ss,mid,st,si*2+1)+constructSTUTIL(a,mid+1,se,si*2+2);
    return st;
}
int *constructST(int a[],int n)
{
    int ht=(int)ceil(log2(n));
    int max_size=2*(int)pow(2,x)-1;
    int *st=new int[max_size];
    // Fillup of the allocated memory
    constructSTUTIL(a,0,n-1,st,0);
    return st;
}
int main()
{
    int a[]={1,3,5,7,9,10}; // segment array
    int n=sizeof(a)/sizeof(a[0]);
    int *st=constructST(a,n); // building the segment tree
    printf("Sum of range of index 1 to 3 is %d\n",getSum(st,n,1,3));
}

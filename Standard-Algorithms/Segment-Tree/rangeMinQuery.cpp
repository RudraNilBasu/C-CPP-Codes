#include<stdio.h>
#include<limits.h>
#include<math.h>
#define MIN(a,b) (a>b)? b: a
using namespace std;
int getMid(int ss, int se){return ss + (se -ss)/2;}
int RMQUTIL(int *st, int a[], int ss, int se, int qs, int qe, int si)
{
    //base cases
    if(se<qs||qe<ss)
    {
        return INT_MAX; // invalid case
    }
    if(qs<=ss && qe>=se)
    {
        // when the entire range falls in the query
        return st[si];
    }
    int mid=getMid(ss,se);
    return MIN(RMQUTIL(st,a,ss,mid,qs,qe,si*2+1),RMQUTIL(st,a,mid+1,se,qs,qe,si*2+2));
    //return MIN(1,2);
}
int RMQ(int *st,int n, int a[], int ss, int se, int qs, int qe, int si)
{
    // checking for invalid query ranges
    if(qs<0||qe>n-1||qs>qe)
    {
        printf("Invalid Range\n");
        return -1;
    }
    // Perform checking
    RMQUTIL(st,a,0,n-1,qs,qe,0);
}
int constructSTUTIL(int a[],int n, int *st, int ss, int se, int si)
{
    // if there is only one element
    if(ss==se)
    {
        st[si]=a[ss];
        return a[ss];
    }
    int mid=getMid(ss,se);
    st[si]=MIN(constructSTUTIL(a,n,st,ss,mid,si*2+1),constructSTUTIL(a,n,st,mid+1,se,si*2+2));
    return st[si];
}
int *constructST(int a[],int n)
{
    int ht=(int)((ceil)(log2(n))); // the height of the tree
    int max_size =2*(int)pow(2,ht)-1; // maximum size of the ST
    int *st=new int[max_size];
    constructSTUTIL(a,n,st,0,n-1,0);
    return st;
}
int main()
{
    int a[]={1,3,2,7,9,11};
    int n=sizeof(a)/sizeof(a[0]);
    int *st=constructST(a,n);
    int qs=1; // the range of the query
    int qe=5; // whose minimum we have to find
    printf("The minimum in the range %d to %d is %d\n",qs,qe,RMQ(st,n,a,0,n-1,qs,qe,0));
    return 0;
}

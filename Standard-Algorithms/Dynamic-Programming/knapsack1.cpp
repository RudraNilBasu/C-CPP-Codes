// implementation of 0/1 knapsack problem
#include<stdio.h>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int knapsack(int W,int wt[],int val[],int n)
{
    if(W==0)
    {
        return 0;
    }
    if(n==0)
    {
        return 0;
    }
    if(wt[n-1]<=W)
    {
        return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
    }
    else
    {
        return knapsack(W,wt,val,n-1);
    }
}
int main()
{
    int W=7;
    int val[4]={1,4,5,7};
    int wt[4]={1,3,4,5};
    int n=sizeof(val)/sizeof(val[0]);
    printf("%d\n",knapsack(W,wt,val,n));
    return 0;
}

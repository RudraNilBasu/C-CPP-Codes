//http://www.spoj.com/problems/NEG2/
#include<stdio.h>
using namespace std;
int main()
{
    int n,k=0,i;
    int a[100]={0};
    scanf("%d",&n);
    if(n==0)
    {
        printf("0\n");
        return 0;
    }
    while(n!=0)
    {
        int rem=n%-2; // calculating remainder
        n/=-2;
        if(rem<0)
        {
            rem+=2;
            n++;
        }
        a[k++]=rem;
    }
    while(k--)
    printf("%d",a[k]);
    printf("\n");
    return 0;
}

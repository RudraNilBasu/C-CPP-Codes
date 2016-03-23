//http://www.spoj.com/problems/BOMARBLE/
#include<stdio.h>
using namespace std;
int main()
{
    int a[1001];
    a[1]=5;
    int i,n;
    for(i=2;i<1001;i++)
    {
        n=a[i-1];
        a[i]=n+(2*(i+1))+(i-1);
    }
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        printf("%d\n",a[n]);
    }
    return 0;
}

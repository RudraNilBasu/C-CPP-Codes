//http://www.spoj.com/problems/SILVER/
#include<stdio.h>
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        int parts=0; // no of parts in which it can be broken = no of bits in n
        while(n)
        {
            n/=2;
            parts++;
        }
        printf("%d\n",parts-1);
    }
}

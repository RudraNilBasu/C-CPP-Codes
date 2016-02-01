/*
http://www.spoj.com/problems/GCD2/
Relevant Stuff - http://www.geeksforgeeks.org/euclids-algorithm-when-and-operations-are-costly/
Added Logic - Performing b%a before hand and storing it in an int
*/
#include<stdio.h>
using namespace std;
char b[300];
int amod(int a, char b[])
{
    int i=0,p=0;
    while(b[i]!='\0')
    {
        p=((p*10)+(b[i]-'0'))%a;
        i++;
    }
    return p;
}
int gcd(int a, int b)
{
    if(b==0 ||a==b) return a;
    if(a==0) return b;

    if( (a&1==0) && (b&1==0) ) // both are even
    {
        return gcd(a>>1, b>>1)<<1;
    }

    if((a&1==0) && (b&1 !=0))
    {
        return gcd(a>>1,b);
    }

    if((a&1 !=0) && (b&1==0))
    {
        return gcd(a,b>>1);
    }

    return a>b?gcd(a-b,b):gcd(a,b-a);
}
int main()
{
    int t,a;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %s",&a,b);
        if(a==0)
        {
            printf("%s\n",b);
        }
        else
        {
            int p=amod(a,b);
            printf("%d\n",gcd(a,p));
        }
    }
    return 0;
}

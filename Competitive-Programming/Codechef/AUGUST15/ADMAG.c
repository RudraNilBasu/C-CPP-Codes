//https://www.codechef.com/AUG15/problems/ADMAG
//https://www.codechef.com/problems/ADMAG

#include<stdio.h>
 
long long int a[100001];
long long int lim=100001;
long long int prev_fibo(long long int n)
{
    long long int i;
    for(i=1;i<=lim;i++)
    {
        if(a[i]==n)
        {
            printf("%lld\n",i);
            return 0;
        }
        else if((a[i]<n) && (a[i+1]>n))
        {
            printf("%lld\n",i);
            return 0;
        }
    }
}
 
int main()
{
    //long long int a[100001];
    long long int t,n,num,fib1=0,fib2=1,fib3=0,i,count=0;
    //arranging the array
    //a[0]=0;
    a[0]=1;
    count=2;
    while(count<lim)
    {
        fib3=fib1+fib2;
        count++;
        a[count-2]=fib3;
        fib1=fib2;
        fib2=fib3;
    }

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        num=prev_fibo(n); // function to return
        /*
        for(i=1;i<len;i++)
        {
            if(a[i]==num)
            {
                printf("%lld\n",i);
                break;
            }
        }
        */
    }
    return 0;
}

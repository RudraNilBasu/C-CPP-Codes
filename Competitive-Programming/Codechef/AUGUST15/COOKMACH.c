//https://www.codechef.com/AUG15/problems/COOKMACH
//https://www.codechef.com/problems/COOKMACH

#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    long long int a,b,count,n;
    double m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        count=0;
        n=log(b)/log(2);
        while(a!=b)
        {
            m=log(1.0*a)/log(2.0);
            printf("\n");
            int x=m;
            if((x-m)==0 && (n>m))
            {
                count+=(n-m);
                break;
            }
            else
            {
                if(a&1)//if odd
                {
                    a=(a-1)/2;
                }
                else
                {
                    a=a/2;
                }
                count++;
            }
        }
        printf("%lld\n",count); 
    }
    return 0;
}

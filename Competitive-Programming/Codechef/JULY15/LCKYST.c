//https://www.codechef.com/JULY15/problems/LCKYST
//https://www.codechef.com/problems/LCKYST

#include<stdio.h>
int main()
{
    int n;
    long long int a,last,copy;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld",&a);
        if((a%10)!=5 && (a%10)!=0)
        {
            printf("%lld\n",a);
        }
        else
        {
            copy=a;
            last = copy % 10; // extracting last digit
            while( (last ==5) || (last ==0))
            {
                if(last==5)
                {
                    a*=4;
                    copy=a;
                    copy/=10;
                    last = copy % 10;
                }
                else if(last == 0)
                {
                    copy/=10;
                    last = copy % 10;
                }
            }
            printf("%lld\n",a);
        }
    }
    return 0;
}

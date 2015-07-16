//http://www.spoj.com/problems/FCTRL2/

#include <stdio.h>
 
int main()
{
    int t,n,carry,x,digitCounter,i,j;
    int a[200];
 
 
    scanf("%d",&t);
 
 
    while(t--)
    {
        scanf("%d",&n);
        a[0]=1;
        carry=0;
        digitCounter = 1;
 
        for(i=1;i<=n;i++)
        {
            for(j=0;j<digitCounter;j++)
            {
                x=a[j]*i + carry;
                a[j] = x%10; // storing the last digit in the correct array position (without the carry)
                carry = x/10;// storing the new value of carry
            }
            //implementing carry in the correct position (for carry in the last position)
            while(carry > 0)
            {
                a[digitCounter]=carry%10;
                carry=carry/10;
                digitCounter++;
            }
        }
        for(i=digitCounter-1;i>=0;i--)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
 

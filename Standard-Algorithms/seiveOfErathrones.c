#include<stdio.h>
int main()
{
    int a[31]={0};
    int i=2,j;
    //a[i]=0 means i is prime
    for(i=2;i<=30;i++)
    {
        if(a[i]==0)
        {
            //marking
            printf("%d\n",i);
            for(j=i;j<=30;j+=i)
            {
                a[j]=1;
            }
        }
    }
    return 0;
}

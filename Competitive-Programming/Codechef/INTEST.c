#include <stdio.h>
unsigned long long int getno();
int main()
{
    unsigned long long int n;
    n=getno();
    unsigned long long int k;
    k=getno();
    unsigned long long int count=0;
    unsigned long long int i;
    for(i=0;i<n;i++)
    {
        if(getno()%k==0)
            count++;
    }
    printf("%lld\n",count);
    return 0;
}
unsigned long long int getno()
{
    unsigned long long int num=0;
    char c=getchar();
    while(c!=' ' && c!='\n')
    {
        num=(num*10)+(c-48);
        c=getchar();
    }
    return num;
}

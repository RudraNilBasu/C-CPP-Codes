//http://www.spoj.com/problems/CPRMT/
#include<stdio.h>
#include<string.h>
using namespace std;
int min(int a,int b)
{
    if(a<b)
    return a;
    return b;
}
int main()
{
    char a[1001];
    char b[1001];
    while(scanf("%s",a)!=EOF && scanf("%s",b)!=EOF)
    {
        char frst[128];
        char lst[128];
        char res[1001];
        int i;
        for(i=97;i<=122;i++)
        {
            frst[i]=0;
            lst[i]=0;
        }
        for(i=0;i<strlen(a);i++)
        {
            frst[a[i]]++;
        }
        for(i=0;i<strlen(b);i++)
        {
            lst[b[i]]++;
        }
        int k=0;
        for(i=97;i<=122;i++)
        {
            if(frst[i]!=0 && lst[i]!=0)
            {
                int j;
                for(j=0;j<min(frst[i],lst[i]);j++)
                {
                    res[k++]=i;
                }
            }
        }
        res[k]='\0';
        printf("%s\n",res);
    }
    return 0;
}

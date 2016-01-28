//http://www.spoj.com/problems/SBANK/
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        char str[40];
        map<string,int> acc;
        map<string,int> ::iterator it;
        scanf("%d\n",&n);
        while(n--)
        {
            gets(str);
            acc[(string)str]++;
        }
        for(it = acc.begin();it!=acc.end();it++)
        {
            printf("%s %d\n",it->first.c_str(),it->second);
        }
        printf("\n");
    }
    return 0;
}

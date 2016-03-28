//http://www.spoj.com/problems/STPAR/
#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    while(1)
    {
        int i,n,k,flag;
        scanf("%d",&n);
        if(n==0) break;
        int a[n],b[n];
        stack<int>ms; // main street
        stack<int>ss; // side street
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        reverse(b,b+n);
        sort(a,a+n);
        for(i=0;i<n;i++)
        {
            ms.push(b[i]);
        }
        k=0;
        flag=0;
        while(!ms.empty())
        {
            int s=ms.top();
            if(s==a[k])
            {
                k++;
                ms.pop();
            }
            else
            {
                if(!ss.empty())
                {
                    if(ss.top()==a[k])
                    {
                        ss.pop();
                        k++;
                    }
                    else
                    {
                        ss.push(ms.top());
                        ms.pop();
                    }
                }
                else
                {
                    ss.push(s);
                    ms.pop();
                }
            }
        }
        while(!ss.empty())
        {
            if(a[k]!=ss.top())
            {
                flag=1;
                break;
            }
            k++;
            ss.pop();
        }
        if(!flag)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}

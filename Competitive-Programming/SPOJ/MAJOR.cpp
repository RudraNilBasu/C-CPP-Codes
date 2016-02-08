//http://www.spoj.com/problems/MAJOR/
#include<stdio.h>
#include<map>

using namespace std;
int a[1000001];
int main()
{
    int t,n,i,flag,count=0,no;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        flag=0;
        count=0;
        no=0;
        map<int,int> table;
        map<int,int>::iterator it;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            table[a[i]]++;
        }
        for(it=table.begin();it!=table.end();++it)
        {
            if(it->second > n/2)
            {
                count++;
                no=it->first;
            }
        }
        if(count==1)
        {
            printf("YES %d\n\n",no);
        }
        else
        {
            printf("NO\n\n");
        }
    }
    return 0;
}

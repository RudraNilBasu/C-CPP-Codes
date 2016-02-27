//http://www.spoj.com/problems/PHONELST/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,n,k=0;
    //char num[11];
    string s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        k=0;
        vector<string>vec;
        while(n--)
        {
            cin>>s;
            vec.push_back(s);
        }
        sort(vec.begin(),vec.end());
        string prev=vec.at(0);
        for(i=1;i<vec.size() && k==0;i++)
        {
            int len=prev.length();
            string now=vec.at(i).substr(0,len);
            if(now==prev)
            {
                k=1;
                printf("NO\n");
                break;
            }
            prev=vec.at(i);
        }
        if(k==0)
        {
            printf("YES\n");
        }
    }
    return 0;
}

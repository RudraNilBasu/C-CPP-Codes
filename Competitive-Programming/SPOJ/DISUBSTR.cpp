//http://www.spoj.com/problems/DISUBSTR/
/*
Explanation - https://www.quora.com/Given-a-string-how-do-I-find-the-number-of-distinct-substrings-of-the-string/answer/Siddharth-Subramanian
Brief Explanation - Create a  Suffix array of the given string (Read this link for that - http://www.geeksforgeeks.org/suffix-array-set-1-introduction/)
Let ans = length of first element in the suffix array
Compare consecutive two elements in the suffix array and find the LCP (longest common prefix) The remaining of the two strings will be a distinct substring
So, ans+= length(Next Element )-lcp(the two elements)
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct suffix
{
    int index;
    char *suff;
};
struct suffix *suffixs;
int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff,b.suff)<0?1:0;
}
int *buildSA(char txt[], int n)
{
    suffixs=new struct suffix[n];
    int i;
    for(i=0;i<n;i++)
    {
        suffixs[i].index=i;
        suffixs[i].suff=(txt+i);
    }
    sort(suffixs,suffixs+n,cmp);
    int sa[n];
    for(i=0;i<n;i++)
    {
        sa[i]=suffixs[i].index;
    }
    return sa;
}
int lcp(char a[], char b[])
{
    int len,i,k=0;
    if(strlen(a)>strlen(b))
    {
        len=strlen(b);
    }
    else
    {
        len=strlen(a);
    }
    for(i=0;i<len;i++)
    {
        if(a[i]==b[i])
        {
            k++;
        }
        else
        {
            return k;
        }
    }
    return k;
}
int main()
{
    int t,i;
    char txt[1001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",txt);
        int n=strlen(txt);
        int *sfx=buildSA(txt,n);
        int ans=strlen(suffixs[0].suff);
        for(i=0;i<n-1;i++)
        {
            ans+=strlen(suffixs[i+1].suff)-lcp(suffixs[i].suff,suffixs[i+1].suff);
        }
        printf("%d\n",ans);
    }
    return 0;
}

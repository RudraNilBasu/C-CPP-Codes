//http://www.spoj.com/problems/NICEBTRE/
#include<cstdio>
#include<iostream>
#include<algorithm>

char tree[10000];
int i=0;

int btree()
{
    if(tree[i]=='l')    // (shifting from left to right subtree)if the subtree/tree has only leaf then return 0
    {
        return 0;
    }
    else
    {
        i++;
        int l=btree();  // calculate height of left subtree
        i++;
        int r=btree();  // calculate height of right subtree
        //return (max(l,r))+1;// +1 since we are not calculating in case of last leaf
        if(l>r)
        {
            return l+1;
        }
        else
        {
            return r+1;
        }
    }
}

int main()
{
    int t,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",tree);
        i=0;
        ans=btree();
        printf("%d\n",ans);
    }
    return 0;
}

//http://www.spoj.com/problems/BRCKTS/
/*
https://kartikkukreja.wordpress.com/2014/11/09/a-simple-approach-to-segment-trees/
*/
#include<stdio.h>
#include<algorithm>
using namespace std;

struct SegmentTreeNode{
    int unmatchedOpenParen;
    int unmatchedClosingParen;

    void assignLeaf(char parenthesis)
    {
        if(parenthesis=='(')
       {
           unmatchedOpenParen=1;
           unmatchedClosingParen=0;
       }
        else
        {
            unmatchedClosingParen=1;
            unmatchedOpenParen=0;
        }
    }

    void merge(SegmentTreeNode& left, SegmentTreeNode& right)
    {
        // merge the values of it's two children
        int newMatches=min(left.unmatchedOpenParen, right.unmatchedClosingParen);
        unmatchedOpenParen=left.unmatchedOpenParen+right.unmatchedOpenParen-newMatches;
        unmatchedClosingParen=left.unmatchedClosingParen+right.unmatchedClosingParen-newMatches;
    }

    bool getValue()
    {
        // to return whether all opening and closing parenthesis are balanced or not
        return unmatchedClosingParen==0 && unmatchedOpenParen==0;
    }
};

template <class T, class V>
class SegmentTree
{
    // T- data type of the array
    SegmentTreeNode* nodes;
    int n;

public:
    SegmentTree(T arr[], int n)
    {
        // constructor to initialise the variables and build the segment tree
        this->n=n;
        nodes = new SegmentTreeNode[getSegmentTreeSize(n)];
        buildTree(arr,1,0,n-1);
    }
    ~SegmentTree()
    {
        delete[] nodes;
    }

    V getValue(int lo, int hi)
    {
        SegmentTreeNode result =  getValue(1, 0, n-1, lo, hi);
        return result.getValue();
    }
    void update(int index, T value)
    {
        update(1, 0, n-1, index, value);
    }

private:
    void buildTree(T arr[], int stIndex, int lo, int hi)
    {
        if(lo==hi)
        {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int mid=(lo+hi)/2;
        int leftchild=2*stIndex,rightchild=leftchild+1;
        buildTree(arr, leftchild, lo, mid);
        buildTree(arr, rightchild, mid+1, hi);
        nodes[stIndex].merge(nodes[leftchild], nodes[rightchild]);
    }
    int getSegmentTreeSize(int n)
    {
        int size=1;
        for(;size<n;size<<=1);
        return size<<1;
    }
    SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi)
    {
        if(lo==left && hi==right)
        {
            return nodes[stIndex];
        }

        int mid=(left + right)/2;

        if(lo>mid)
        {
            return getValue(2*stIndex+1, mid+1, right, lo, hi);
        }
        if(hi<=mid)
        {
            return getValue(2*stIndex, left, mid, lo, hi);
        }

        SegmentTreeNode leftChildResult = getValue(2*stIndex, left, mid, lo, mid);
        SegmentTreeNode rightChildResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);

        SegmentTreeNode result;
        result.merge(leftChildResult, rightChildResult);

        return result;
    }

    void update(int stIndex, int lo, int hi, int index, T value)
    {
        if(lo==hi)
        {
            nodes[stIndex].assignLeaf(value);
            return;
        }

        int left = 2*stIndex, right=left+1, mid=(lo+hi)/2;

        if(index<=mid)
        {
            update(left, lo, mid, index, value);
        }
        else
        {
            update(right, mid+1, hi, index, value);
        }

        nodes[stIndex].merge(nodes[left], nodes[right]);
    }
};

int main()
{
    int t,n,m,k;
    for(t=1;t<=10;t++)
    {
        scanf("%d",&n);
        char a[n+1];
        scanf("%s",a);

        SegmentTree<char,bool> st(a, n);

        scanf("%d",&m);

        printf("Test %d:\n",t);
        while(m--)
        {
            scanf("%d",&k);
            if(k!=0)
            {
                k--;
                a[k]=(a[k]=='(')?')':'(';
                st.update(k,a[k]);
            }
            else
            {
                if(st.getValue(0,n-1))
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}

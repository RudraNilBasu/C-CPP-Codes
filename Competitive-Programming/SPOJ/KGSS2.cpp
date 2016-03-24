//http://www.spoj.com/problems/KGSS/
#include<stdio.h>
using namespace std;
int max(int a, int b)
{
    if(a>=b)
    return a;
    return b;
}
int min(int a, int b)
{
    if(a<=b)
    return a;
    return b;
}
struct SegmentTreeNode{
    int secondMax; // 2nd maximum
    int maxNo; // the maximum number in this range

    void assignLeaf(int number)
    {
        secondMax = -1;
        maxNo = number;
    }

    void merge(struct SegmentTreeNode& left, struct SegmentTreeNode& right)
    {
        maxNo = max( left.maxNo, right.maxNo );
        secondMax = min(max(left.maxNo, right.secondMax), max(right.maxNo, left.secondMax));
    }

    int getValue()
    {
        return maxNo+secondMax;
    }
};

template <class T, class V>
class SegmentTree
{
    SegmentTreeNode* nodes;
    int n;

public:
    SegmentTree(T arr[], int n)
    {
        this->n = n;
        nodes = new SegmentTreeNode[getSize(n)];
        buildTree(arr, 1, 0, n-1);
    }
    ~SegmentTree()
    {
        delete[] nodes;
    }
    void update(int index, T value)
    {
        update(1,0,n-1,index, value);
    }

    V getValue(int lo, int hi)
    {
        SegmentTreeNode val = getValue(1,0,n-1,lo,hi);
        return val.getValue();
    }

private:
    void buildTree(T arr[], int stIndex, int lo, int hi)
    {
        if(lo==hi)
        {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int left=stIndex*2,right=left+1,mid=(lo+hi)/2;
        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid+1, hi);

        nodes[stIndex].merge(nodes[left], nodes[right]);
    }

    int getSize(int n)
    {
        // maximum size = nearest power of 2
        int size=1;
        for(;size<n;size<<=1);
        return size<<1;
    }

    void update(int stIndex, int lo, int hi, int index, T value)
    {
        if(lo==hi)
        {
            nodes[stIndex].assignLeaf(value);
            return;
        }

        int left = 2*stIndex, right = left+1, mid = (lo+hi)/2;
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

    SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi)
    {
        if(lo==left && hi==right)
        {
            return nodes[stIndex];
        }

        int mid = (left+right)/2;

        if(lo > mid)
        {
            return getValue(2*stIndex+1,mid+1,right,lo,hi);
        }
        else if(hi <= mid)
        {
            return getValue(2*stIndex, left, mid, lo, hi);
        }

        SegmentTreeNode leftChildRes = getValue(2*stIndex, left, mid, lo, mid);
        SegmentTreeNode rightChildRes = getValue(2*stIndex+1, mid+1, right, mid+1, hi);

        SegmentTreeNode result;
        result.merge(leftChildRes, rightChildRes);

        return result;
    }
};

int main()
{
    int n,i,q;

    scanf("%d",&n);

    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    SegmentTree<int,int> st(a,n);

    scanf("%d",&q);
    while(q--)
    {
        char ch;
        int x;

        scanf(" %c %d %d", &ch , &x,&i);

        if(ch=='Q')
        {
            printf("%d\n",st.getValue(x-1,i-1));
        }
        else if(ch=='U')
        {
            a[x-1]=i;
            st.update(x-1,i);
        }
    }

    return 0;
}

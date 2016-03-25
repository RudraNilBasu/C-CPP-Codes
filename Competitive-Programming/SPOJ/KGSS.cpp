//http://www.spoj.com/problems/KGSS/
#include<stdio.h>
using namespace std;
int max(int a, int b)
{
    if(a>=b)
    return a;
    return b;
}
struct SegmentTreeNode{
    int maxInThisRange; // computes the maximum sum of two numbers in this range
    int maxNo; // the maximum number in this range
    bool isLeaf;

    void assignLeaf(int number)
    {
        maxInThisRange = number;
        maxNo = number;
        isLeaf=true;
    }

    void merge(struct SegmentTreeNode& left, struct SegmentTreeNode& right)
    {
        // to merge left and right nodes
        //maxInThisRange = left.maxNo + right.maxNo;
        int temp=-10000000;
        if(left.maxInThisRange >= right.maxInThisRange && (!left.isLeaf ))
        {
            temp = left.maxInThisRange;
        }
        else if(left.maxInThisRange < right.maxInThisRange && !right.isLeaf)
        {
            temp = right.maxInThisRange;
        }
        if( (left.maxNo + right.maxNo) > temp )
        {
            temp = left.maxNo + right.maxNo;
        }

        maxInThisRange = temp;

        maxNo = max(left.maxNo, right.maxNo);
        isLeaf=false;
    }

    int getValue()
    {
        return maxInThisRange;
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

        //scanf("%d %d %d",&ch,&i,&x);
        scanf(" %c %d %d", &ch , &x,&i);

        if(ch=='Q')
        {
            printf("%d\n",st.getValue(x-1,i-1)); // problem with 2 4
        }
        else if(ch=='U')
        {
            a[x-1]=i;
            st.update(x-1,i);
        }
    }

    return 0;
}

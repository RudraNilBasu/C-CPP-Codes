#include<stdio.h>
#include<map>
using namespace std;
struct SegmentTreeNode {
	int leftVal,rightVal,leftBest,rightBest,best, bestVal;
	void assignLeaf(int value)
	{
		leftBest=1;
		rightBest=1;
		best=1;
		leftVal=value;
		rightVal=value;
		bestVal=value;
	}
	void merge(SegmentTreeNode& left, SegmentTreeNode& right)
	{
		if( left.leftVal == right.rightVal ) {
			leftVal=rightVal=bestVal=left.leftVal;
			leftBest=rightBest=best=left.leftBest+right.rightBest;
		} else {
			// updating left and right val and freq
			leftVal=left.leftVal;
			leftBest=left.leftBest;
			rightVal=right.rightVal;
			rightBest=right.rightBest;

			if( left.leftVal==right.leftVal ) {
				leftBest=left.leftBest+right.leftBest;
			}
			if( left.rightVal==right.rightVal ) {
				rightBest=left.rightBest+right.rightBest;
			}

			// updating best and bestVal
			if( left.best>right.best ) {
				best=left.best;
				bestVal=left.bestVal;
			} else {
				best=right.best;
				bestVal=right.bestVal;
			}

			if( left.rightVal==right.leftVal ) {
				int temp=left.rightBest+right.leftBest;
				if(temp>best) {
					best=temp;
					bestVal=left.rightVal;
				}
			}
		}
	}
	int getValue()
	{
		return best;
	}
};
template<class T, class V>
class SegmentTree
{
	SegmentTreeNode* nodes;
	int n;
public:
	SegmentTree(T arr[], int n)
	{
		this->n=n;
		nodes=new SegmentTreeNode[getSegmentTreeSize(n)];
		buildTree(arr,1,0,n-1);
	}
	~SegmentTree()
	{
		delete[] nodes;
	}
	int getValue(int lo, int hi)
	{
		SegmentTreeNode result=getValue(1,0,n-1,lo,hi);
		return result.getValue();
	}
private:
	int getSegmentTreeSize(int n)
	{
		int i;
		for(i=1;i<n;i<<=1);
		return i<<1;
	}
	void buildTree(int arr[], int stIndex, int lo, int hi)
	{
		if(lo==hi)
		{
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		int left=(2*stIndex),right=left+1,mid=(lo+hi)/2;
		buildTree(arr,left,lo,mid);
		buildTree(arr,right,mid+1,hi);
		nodes[stIndex].merge(nodes[left],nodes[right]);
	}
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi)
	{
		if((left==lo) && (right==hi)) {
			return nodes[stIndex];
		}
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);

		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}
};
int input(int a[], int n)
{
	int i;
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
}
int main()
{
	int n,q,i,j,x,y,max,no;
	while(1) {
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&q);
		int a[n];
		input(a,n);
		SegmentTree<int,int> st(a,n);
		//while(q--) {
		while(q--) {
			scanf("%d",&x);
			scanf("%d",&y);
			max=-1;
			x--;
			y--; // making index start from 0
			printf("%d\n",st.getValue(x,y));
			/*
			for(i=x;i<=y;i++) {
				int num=a[i];
				int freq=1;
				for(j=i+1;j<=y;j++) {
					if(a[j]==num) {
						freq++;
					} else {
						break;
					}
				}
				i=j-1; // i gets incremented to j later
				if(freq>max) {
					max=freq;
				}
			}
			printf("%d\n",max);
			*/
		}
	}
	return 0;
}

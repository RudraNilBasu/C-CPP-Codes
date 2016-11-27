#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct SegmentTreeNode {
	int val;
	int n; // current value of the leaf node
	
	void assignLeaf(int num) {
		n=num;
		if(num%3==0) {
			val=1;
		} else {
			val=0;
		}
	}

	void add(int value)
	{
		n+=value;
		if(n%3==0) {
			val=1;
		} else {
			val=0;
		}
	}
	
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		val=left.val+right.val;
	}
	
	int getValue() {
		return val;
	}
};

//template<class T, class V>
class SegmentTree {
	SegmentTreeNode* nodes;
	int *lazy;
	int N;
	
public:
	SegmentTree(int N) {
		this->N = N;
		int sz=getSegmentTreeSize(N);
		nodes = new SegmentTreeNode[sz];
		lazy = new int[sz];
		memset(lazy, 0, sizeof(lazy));
		buildTree(1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	int getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	
	void update(int l, int r, int value) {
		update(1, 0, N-1, l, r, value);
	}
	
private:	
	void buildTree(int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(0);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(left, lo, mid);
		buildTree(right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
	
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];
			
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
	
	int getSegmentTreeSize(int N) {
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}
	
	void update(int stIndex, int lo, int hi, int l, int r, int value) {
		// out of range
		if(lo>hi || lo>r ||hi<l) {
			return;
		}
		if (lo == hi) {
			//nodes[stIndex].assignLeaf(value+);
			nodes[stIndex].add(value);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		/*
		if (stIndex <= mid)
			update(left, lo, mid, l, r, value);
		else
			update(right, mid+1, hi, l, r, value);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
		*/
		update(left, lo, mid, l, r, value);
		update(right, mid+1, hi, l, r, value);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

int main() {
	int n,q,i;
	scanf("%d %d",&n,&q);
	int a[n];
	for(i=0;i<n;i++) {
		a[i]=0;
	}
	//SegmentTree<int,int> st(a,n);
	SegmentTree st(n);
	int op,x,y;
	while(q--) {
		scanf("%d %d %d",&op,&x,&y);
		if(op==0) {
			st.update(x, y, 1);
			/*
			for(i=x;i<=y;i++) {
				st.update(i,1);
				a[i]++;
			}
			*/
		} else {
			printf("%d\n",st.getValue(x,y));
		}
		/*
		printf("----------\n");
		for(i=0;i<n;i++) {
			printf("%d\n",a[i]);
		}
		printf("----------\n");
		*/
	}
	return 0;
}

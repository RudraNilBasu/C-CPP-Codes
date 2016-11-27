#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct SegmentTreeNode {
	int val;
	int n; // current value of the leaf node
	int rem1,rem2,rem0; // how many no s gives remainder 
	// 0, 1 or 2 on dividing by 3
	void assignLeaf(int num) {
		n=num;
		if(num%3==0) {
			val=1;
		} else {
			val=0;
		}
		if(n%3==0) {
			rem0=1;
			rem1=0;
			rem2=0;
		} else if(n%3==1) {
			rem0=0;
			rem1=1;
			rem2=0;
		} else if(n%3==2) {
			rem0=0;
			rem1=0;
			rem2=1;
		}

	}

	void add(int value)
	{
		// add value of leaf
		n+=value;
		if(n%3==0) {
			val=1;
		} else {
			val=0;
		}
		if(n%3==0) {
			rem0=1;
			rem1=0;
			rem2=0;
		} else if(n%3==1) {
			rem0=0;
			rem1=1;
			rem2=0;
		} else if(n%3==2) {
			rem0=0;
			rem1=0;
			rem2=1;
		}
	}
	
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		val=left.val+right.val;
		rem0=left.rem0+right.rem0;
		rem1=left.rem1+right.rem1;
		rem2=left.rem2+right.rem2;
	}
	
	int getValue() {
		return rem0;
		//return val;
	}
};

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
		if(lazy[stIndex]!=0) {
			// if not leaf node
			if(lo!=hi) {
				int left=2*stIndex;
				int right=left+1;
				lazy[left]=(lazy[left]+lazy[stIndex])%3;
				lazy[right]=(lazy[right]+lazy[stIndex])%3;
			}
			if(lazy[stIndex]==1) {
				// shift by one place
				int _a=nodes[stIndex].rem0;
				int _b=nodes[stIndex].rem1;
				int _c=nodes[stIndex].rem2;
				nodes[stIndex].rem1=_a;
				nodes[stIndex].rem2=_b;
				nodes[stIndex].rem0=_c;
			} else if(lazy[stIndex]==2) {
				// shift by 2 places
				int _a=nodes[stIndex].rem0;
				int _b=nodes[stIndex].rem1;
				int _c=nodes[stIndex].rem2;
				nodes[stIndex].rem1=_c; // b
				nodes[stIndex].rem2=_a; // c
				nodes[stIndex].rem0=_b; // a
			}
			lazy[stIndex]=0;
		}
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
		if(lazy[stIndex]!=0) {
			// if not leaf node
			if(lo!=hi) {
				int left=2*stIndex;
				int right=left+1;
				lazy[left]=(lazy[left]+lazy[stIndex])%3;
				lazy[right]=(lazy[right]+lazy[stIndex])%3;
			}
			if(lazy[stIndex]==1) {
				// shift by one place
				int _a=nodes[stIndex].rem0;
				int _b=nodes[stIndex].rem1;
				int _c=nodes[stIndex].rem2;
				nodes[stIndex].rem1=_a;
				nodes[stIndex].rem2=_b;
				nodes[stIndex].rem0=_c;
			} else if(lazy[stIndex]==2) {
				// shift by 2 places
				int _a=nodes[stIndex].rem0;
				int _b=nodes[stIndex].rem1;
				int _c=nodes[stIndex].rem2;
				nodes[stIndex].rem1=_c; // b
				nodes[stIndex].rem2=_a; // c
				nodes[stIndex].rem0=_b; // a
			}
			lazy[stIndex]=0;
		}
		// out of range
		if(lo>hi || lo>r ||hi<l) {
			return;
		}
		if(lo>=l && hi<=r) {
			if(lo!=hi) {
				// not leaf node
				// do lazy
				lazy[stIndex*2]=(1+lazy[stIndex*2])%3;
				lazy[(stIndex*2)+1]=(1+lazy[(stIndex*2)+1])%3;
			}
			int _a=nodes[stIndex].rem0;
			int _b=nodes[stIndex].rem1;
			int _c=nodes[stIndex].rem2;
			nodes[stIndex].rem1=_a;
			nodes[stIndex].rem2=_b;
			nodes[stIndex].rem0=_c;
			return;
		}
		/*
		if (lo == hi) {
			nodes[stIndex].add(value);
			return;
		}
		*/
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		update(left, lo, mid, l, r, value);
		update(right, mid+1, hi, l, r, value);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

int main() {
	int n,q,i;
	scanf("%d %d",&n,&q);
	SegmentTree st(n);
	int op,x,y;
	while(q--) {
		scanf("%d %d %d",&op,&x,&y);
		if(op==0) {
			st.update(x, y, 1);
		} else {
			printf("%d\n",st.getValue(x,y));
		}
	}
	return 0;
}

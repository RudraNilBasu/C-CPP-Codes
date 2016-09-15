#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

#define ll long long int

using namespace std;

int primes[1000001];

int sieve()
{
	int i,j;
	memset(primes, 0, sizeof(primes));
	primes[1]=1;
	for(i=2;i<=1000000;i++) {
		if(primes[i]==0) {
			for(j=i+i;j<=1000000;j+=i) {
				primes[j]=1;
			}
		}
	}
}
/* 
int lpd(int n)
{
	int i;

	if(!primes[n]) {
		return n;
	}

	for(i=2;i<=1000000;i++) {
		if(primes[i]==0 && n%i==0) {
			return i;
		}
		if(i>n) {
			return 1;
		}
	}
	return 1;
}
*/
int lpd(int n)
{
	if (n==0 || n==1) return n;
	if (n%2==0) return 2;
	if (n%3==0) return 3;
	if (n%5==0) return 5;


	if(!primes[n]) {
		return n;
	}

	for (int i = 7; (i*i) <= n; i += 30 ) {
		if ( n % i == 0 ) {
			return i;
		}
		if ( n % ( i+4 ) == 0) {
			return i+4;
		}
		if ( n % ( i+6 ) == 0) {
			return i+6;
		}
		if ( n % ( i+10 ) == 0) {
			return i+10;
		}
		if ( n % ( i+12 ) == 0) {
			return i+12;
		}
		if ( n % ( i+16 ) == 0) {
			return i+16;
		}
		if ( n % ( i+22 ) == 0) {
			return i+22;
		}
		if ( n % ( i+24 ) == 0) {
			return i+24;
		}
	}
	return n;
}
struct SegmentTreeNode {
	int maxNum;

	void assignLeaf(int num) {
		maxNum = num;
	}

	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		maxNum = max(lpd(left.maxNum), lpd(right.maxNum));
	}

	int getValue() {
		return maxNum;
	}
};

template<class T, class V>
class SegmentTree {
	SegmentTreeNode* nodes;
	int N;

	public:
	SegmentTree(T arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}

	~SegmentTree() {
		delete[] nodes;
	}

	V getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}

	void update(int index, T value) {
		update(1, 0, N-1, index, value);
	}

	private:	
	void buildTree(T arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}

		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
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

	void update(int stIndex, int lo, int hi, int index, T value) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(value);
			return;
		}

		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		if (index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);

		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};


int main()
{
	sieve();
	int t,n,m,i,op,x,y,val;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&m);
		int a[n];
		for(i=0;i<n;i++) {
			scanf("%d",a+i);
		}
		SegmentTree<int,int> st(a,n);
		while(m--) {
			scanf("%d %d %d",&op,&x,&y);
			if(!op) {
				// update
				for(i=x-1;i<=y-1;i++) {
					a[i]=a[i]/lpd(a[i]);
					st.update(i,a[i]);
				}
				/*
				for(i=0;i<n;i++) {
					printf("%d ",a[i]);
				}
				printf("\n");
				*/
			} else {
				// get
				printf("%d ",st.getValue(x-1,y-1));
			}
		}
		printf("\n");
	}
	return 0;
}


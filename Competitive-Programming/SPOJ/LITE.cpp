#include<stdio.h>
using namespace std;
int tree[270000];
bool lazy[270000];
void update(int stIndex, int left, int right, int lo, int hi)
{
	if(lazy[stIndex]) {
		lazy[stIndex]=false;
		// applying the previous updates
		tree[stIndex]=(right-left+1) - tree[stIndex];
		if(left<right) {
			// if not leaf node
			lazy[2*stIndex]=!lazy[2*stIndex];
			lazy[(2*stIndex)+1]=!lazy[(2*stIndex)+1];
		}
	}
	if( (left>right) || (lo>right) || (hi<left) )
		return;
	// complete overlap
	if(lo<=left && hi>=right) {
		// applying the current update
		tree[stIndex] = (right-left+1) - tree[stIndex];
		if(left<right) {
			// if not leaf node
			// marking laz[] for the child nodes
			lazy[(2*stIndex)]=!lazy[(2*stIndex)];
			lazy[(2*stIndex)+1]=!lazy[(2*stIndex)+1];
		}
		return;
	}
	// partial overlap condition
	int mid=(left+right)/2;
	update((stIndex*2),left,mid,lo,hi);
	update(((stIndex*2)+1),mid+1,right,lo,hi);
	if(left<right) {
		tree[stIndex]=tree[(2*stIndex)]+tree[(2*stIndex)+1];
	}
}
int getValue(int stIndex, int left, int right, int lo, int hi)
{
	//printf("Node = %d\tleft=%d\tright=%d\tlo=%d\thi=%d\n",stIndex,left,right,lo,hi);
	if((left>right) || (lo>right) || (hi<left) )
		return 0;
	if(lazy[stIndex]) {
		lazy[stIndex]=false;
		// applying previous changes
		tree[stIndex]=(right-left+1) - tree[stIndex];
		if(left<right) {	
			// if not leaf node
			lazy[2*stIndex]=!lazy[2*stIndex];
			lazy[(2*stIndex)+1]=!lazy[(2*stIndex)+1];
		}
	}
	// complete overlap
	if(lo<=left && hi>=right) {
		return tree[stIndex];
	}
	int mid=(left+right)/2;
	return getValue((2*stIndex),left,mid,lo,hi)+getValue(((2*stIndex)+1),mid+1,right,lo,hi);
}
int main()
{
	int N,M;
	int op,x,y;
	scanf("%d %d",&N,&M);
	while(M--) {
		scanf("%d %d %d",&op,&x,&y);
		if(op) {
			printf("%d\n",getValue(1,1,N,x,y));
		} else {
			update(1,1,N,x,y);
		}
	}
	return 0;
}

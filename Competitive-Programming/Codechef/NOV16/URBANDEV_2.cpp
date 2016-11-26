#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iostream>

#define ll long long int
#define ull unsigned ll

#define PI 3.14159265
//#define DEBUG(X) cout << (X) << endl;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

// inputs
#define inpd(x) scanf("%d",&x)
#define inpc(x) scanf("%c",&x)

using namespace std;

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int max3(int a, int b, int c)
{
	return max(a,max(b,c));
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

typedef struct horz {
	int no;
	int y;
	int x1;
	int x2;
}horz;

typedef struct vert {
	int no;
	int x;
	int y1;
	int y2;
}vert;

typedef struct SegmentTreeNode {
	int no; // no of 1 in the range
	void assignLeaf(int num)
	{
		no=num;
	}
	void merge(SegmentTreeNode& left, SegmentTreeNode& right)
	{
		no=left.no+right.no;
	}
	int getValue()
	{
		return no;
	}
}SegmentTreeNode;

class SegmentTree 
{
	SegmentTreeNode* nodes;
	int N;
public:
	SegmentTree(int N)
	{
		this->N=N;
		nodes=new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(1,0,N-1);
	}
	int getValue(int lo, int hi)
	{
		SegmentTreeNode result=getValue(1,0,N-1,lo,hi);
		return result.getValue();
	}
	void update(int index, int value)
	{
		update(1,0,N-1, index, value);
	}
private:
	void buildTree(int stIndex, int lo, int hi)
	{
		if(lo==hi) {
			nodes[stIndex].assignLeaf(0);
			return;
		}
		int left=2*stIndex,right=left+1,mid=(lo+hi)/2;
		buildTree(left, lo, mid);
		buildTree(right, mid+1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi)
	{
		if(left==lo && right==hi) {
			return nodes[stIndex];
		}
		int mid=(left+right)/2;
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
	void update(int stIndex, int lo, int hi, int index, int value) {
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
	int n,i,j,x1,x2,y1,y2;
	scanf("%d",&n);
	vector<vert> v; // store all vertical lines
	vector<horz> h; // store all horizontal lines
	for(i=1;i<=n;i++) {
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1==x2) {
			// vertical
			vert temp;
			temp.no=i;
			temp.x=x1;
			temp.y1=min(y1,y2);
			temp.y2=max(y1,y2);
			v.push_back(temp);
			//cout<<"Vertical pushed\n";
		} else if(y1==y2) {
			// horizontal
			horz temp;
			temp.no=i;
			temp.y=y1;
			temp.x1=min(x1,x2);
			temp.x2=max(x1,x2);
			h.push_back(temp);
			//cout<<"Horizontal pushed\n";
		}
	}
	int ans=0;
	int city[n+1];
	memset(city, 0, sizeof(city));
	//int sweep[100001]; // the sweeping line
	for(i=0;i<v.size();i++) {
		int x_corr=v[i].x;
		int _y1=v[i].y1;
		int _y2=v[i].y2;
		// sweep array creation for this vertical segment
		// create the array sweep[i]=1 when intersects
		//memset(sweep, 0, sizeof(sweep));
		// create seg tree
		SegmentTree st(100001);
		for(j=0;j<h.size();j++) {
			int _x1=h[j].x1;
			int _x2=h[j].x2;
			// update seg tree value of h[j].y to 1
			if(x_corr>=_x1 && x_corr<=_x2) {
				// check corner case (round)
				//sweep[h[j].y]=1;
				// update seg tree value of h[j].y to 1
				/*
				if(x_corr==_x1) {
					if(h[j].y==_y1 || h[j].y==_y2) {}
				} else if(x_corr==_x2) {
					if()
				}
				*/
				if((x_corr==_x1||x_corr==_x2)&&(h[j].y==_y1||h[j].y==_y2)) {}
				else {
					st.update(h[j].y,1);
				}
			}
		}
		// query for range _y1 to _y2
		int x=st.getValue(_y1, _y2);
		ans+=x;
		city[v[i].no]=x;
	}
	for(i=0;i<h.size();i++) {
		int y_corr=h[i].y;
		int _x1=h[i].x1;
		int _x2=h[i].x2;
		SegmentTree st(100001);
		for(j=0;j<v.size();j++) {
			int _y1=v[j].y1;
			int _y2=v[j].y2;
			if(_y1<=y_corr && _y2>=y_corr) {
				if((_x1==v[j].x||_x2==v[j].x)&&(y_corr==v[j].y1||y_corr==v[j].y2)) {}
				else {
					st.update(v[j].x, 1);
				}
			}
		}
		int x=st.getValue(_x1, _x2);
		city[h[i].no]=x;
	}
	cout<<ans<<endl;
	for(i=1;i<=n;i++) {
		cout<<city[i]<<" ";
	}
	cout<<"\n";
	return 0;
}


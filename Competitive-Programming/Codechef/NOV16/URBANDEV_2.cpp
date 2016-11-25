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
	void assignValue(int num)
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
	//
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
	//int sweep[100001]; // the sweeping line
	for(i=0;i<v.size();i++) {
		int x_corr=v[i].x;
		int _y1=v[i].y1;
		int _y2=[i].y2;
		// sweep array creation for this vertical segment
		// create the array sweep[i]=1 when intersects
		//memset(sweep, 0, sizeof(sweep));
		// create seg tree
		for(j=0;j<h.size();j++) {
			int _x1=h[j].x1;
			int _x2=h[j].x2;
			// update seg tree value of h[j].y to 1
			if(x_corr>=_x1 && x_corr<=_x2) {
				//sweep[h[j].y]=1;
				// update seg tree value of h[j].y to 1
			}
		}
		// query for range _y1 to _y2
	}
	return 0;
}


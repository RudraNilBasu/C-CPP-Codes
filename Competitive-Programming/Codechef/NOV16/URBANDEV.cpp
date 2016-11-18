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

int main()
{
	int n,i,j,x1,x2,y1,y2;
	scanf("%d",&n);
	vector<vert> v;
	vector<horz> h;
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
	int c=0;
	int city[n+1];
	memset(city, 0, sizeof(city));
	for(i=0;i<v.size();i++) {
		vert curr_vert=v[i];
		for(j=0;j<h.size();j++) {
			if( h[j].x1<=curr_vert.x && h[j].x2>=curr_vert.x && curr_vert.y1<=h[j].y && curr_vert.y2>=h[j].y) {
				/*
				if(h[j].y!=curr_vert.y2 && h[j].y!=curr_vert.y1) {
					c++;
					city[ h[j].no ]++;
					city[ curr_vert.no ]++;
				}
				*/
				if( h[j].y==curr_vert.y1) {
					if(h[j].x1==curr_vert.x) {
						//
					} else if(h[j].x2==curr_vert.x) {
						//
					} else {
						c++;
						city[ h[j].no ]++;
						city[ curr_vert.no ]++;
					}
				} else if(h[j].y==curr_vert.y2) {
					if(h[j].x1==curr_vert.x) {
						//
					} else if(h[j].x2==curr_vert.x) {
						//
					} else {
						c++;
						city[ h[j].no ]++;
						city[ curr_vert.no ]++;
					}
				} else {
					c++;
					city[ h[j].no ]++;
					city[ curr_vert.no ]++;
				}
			}
		}
	}
	printf("%d\n",c);
	for(i=1;i<=n;i++) {
		printf("%d ",city[i]);
	}
	printf("\n");
	return 0;
}


#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef struct node{
	int x;
	int y;
	int val;
}node;
typedef struct quad{
	int a;
	int b;
	int c;
	int d;
}quad;
int main()
{
	int i,j;
	vector<node> l,r;
	for(i=2;i<=100;i++) {
		for(j=2;j<=100;j++) {
			// calculating all combinations of a^3 - d^3
			// and b^3 + c^3
			node temp;
			temp.x=i;
			temp.y=j;
			temp.val=(i*i*i)-(j*j*j);
			l.push_back(temp);
			temp.val=(i*i*i)+(j*j*j);
			r.push_back(temp);
		}
	}
	vector<quad> res;
	for(i=0;i<l.size();i++) {
		for(j=0;j<r.size();j++) {
			if( l[i].val==r[j].val ) {
				quad temp;
				temp.a=l[i].x;
				temp.b=l[i].y;
				temp.c=r[j].x;
				temp.d=r[j].y;
				res.push_back(temp);
			}
		}
	}
	int hold[3];
	vector<int> g[101];
	for(i=0;i<res.size();i++) {
		int flag=0;
		if( std::find(g[res[i].a].begin(), g[res[i].a].end(),res[i].b)!=g[res[i].a].end() ) {
			flag++;
		}

		if( std::find(g[res[i].a].begin(), g[res[i].a].end(),res[i].c)!=g[res[i].a].end() ) {
			flag++;
		}
		if( std::find(g[res[i].a].begin(), g[res[i].a].end(),res[i].d)!=g[res[i].a].end() ) {
			flag++;
		}
		if(flag!=3) {
			printf("Cube = %d, Triple = (%d,%d,%d)\n",res[i].a,res[i].b,res[i].c,res[i].d);
			g[res[i].a].push_back(res[i].b);

			g[res[i].a].push_back(res[i].c);
			g[res[i].a].push_back(res[i].d);
		}
	}
	return 0;
}

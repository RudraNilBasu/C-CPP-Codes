#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int n,size=0;
	scanf("%d",&n);
	vector<int> g[n+1];
	int i,j,x,y;
	for(i=1;i<=n-1;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	while(1) {
		int leafNode=-1,parent;
		int remain=0;
		for(i=1;i<=n;i++) {
			if(g[i].size()!=0)
                                 remain=1;
			if(g[i].size()==1) {
				leafNode=i;
				break;
			}
			if(g[i].size()!=0)
				remain=1;
		}
		if(remain==0)
			break;
		if(leafNode!=-1) {
			parent=g[leafNode][0];
			g[leafNode].clear();
			size++;
			for(i=0;i<g[parent].size();i++) {
				int x=g[parent][i];
				for(j=0;j<g[x].size();j++) {
					if(g[x][j]==parent) {
						g[x].erase(g[x].begin()+j);
					}
				}
			}
			g[parent].clear();
		}
	}
	printf("%d\n",size);
}

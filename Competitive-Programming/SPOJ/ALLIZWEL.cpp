#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define ll long long int

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

using namespace std;

char s[101][101];
int r,c;
char str={'A','L','L','I','Z','Z','W','E','L','L'};

typedef struct node {
	int x;
	int y;
}node;

bool check(int n, int m)
{
	node cell[8];
	bool visited[c][r];
	memset(visited, false, sizeof(visited));
	int k=1;
}

int main()
{
	int t,i,j;
	bool done;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&r,&c);
		//char s[c][r+1];
		for(i=0;i<c;i++) {
			scanf("%s",s[i]);
		}
		done=false;
		for(i=0;i<c && !done;i++) {
			for(j=0;j<r && !done;j++) {
				if(s[i][j]=='A' && check(i,j)) {
					printf("YES\n");
					done=true;
					break;
				}
			}
		}
		if(!done) {
			printf("NO\n");
		}
	}
	return 0;
}


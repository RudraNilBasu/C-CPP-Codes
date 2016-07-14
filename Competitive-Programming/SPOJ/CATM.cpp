#include<stdio.h>
#include<queue>
using namespace std;
typedef struct cell {
	int x;
	int y;
}cell;
int isValid(cell temp, int n, int m)
{
	if(temp.x<1 || temp.y<1)
		return 0;
	if(temp.x>n || temp.y>m)
		return 0;
	return 1;
}
int edge(cell temp, int n, int m)
{
	if(temp.x==1)
		return 1;
	if(temp.x==n)
		return 1;
	if(temp.y==1 || temp.y==m)
		return 1;
	return 0;
}
int main()
{
	int n,m,k,i,j;
	cell moves[4];

	moves[0].x=1;moves[0].y=0;
	moves[1].x=0;moves[1].y=1;
	moves[2].x=-1;moves[2].y=0;
	moves[3].x=0;moves[3].y=-1;

	scanf("%d %d",&n,&m);
	scanf("%d",&k);
	while(k--) {
		cell mouse,cat1,cat2;
		scanf("%d %d %d %d %d %d",&mouse.x,&mouse.y,&cat1.x,&cat1.y,&cat2.x,&cat2.y);
		int distM[n+1][m+1],c1[n+1][m+1],c2[n+1][m+1];
		for(i=0;i<n+1;i++) {
			for(j=0;j<m+1;j++) {
				distM[i][j]=c1[i][j]=c2[i][j]=-1;
			}
		}
		queue<cell> qm,qc1,qc2;


		qc1.push(cat1);
		c1[cat1.x][cat1.y]=0;
		while(!qc1.empty()) {
			cell u=qc1.front();
			qc1.pop();

			for(i=0;i<4;i++) {
				cell temp;
				temp.x=u.x+moves[i].x;
				temp.y=u.y+moves[i].y;

				if( isValid(temp,n,m) && c1[temp.x][temp.y]==-1 ) {
					c1[temp.x][temp.y]=c1[u.x][u.y]+1;
						qc1.push(temp);
				}
			}
		}


		c2[cat2.x][cat2.y]=0;
		qc2.push(cat2);
		while(!qc2.empty()) {
			cell u=qc2.front();
			qc2.pop();

			for(i=0;i<4;i++) {
				cell temp;
				temp.x=u.x+moves[i].x;
				temp.y=u.y+moves[i].y;

				if( isValid(temp,n,m) && c2[temp.x][temp.y]==-1 ) {
					c2[temp.x][temp.y]=c2[u.x][u.y]+1;
						qc2.push(temp);
				}
			}
		}


		qm.push(mouse);
		distM[mouse.x][mouse.y]=0;
		while(!qm.empty()) {
			cell u=qm.front();
			qm.pop();

			for(i=0;i<4;i++) {
				cell temp;
				temp.x=u.x+moves[i].x;
				temp.y=u.y+moves[i].y;

				if( isValid(temp,n,m) && distM[temp.x][temp.y]==-1 
						&& (c1[temp.x][temp.y]!=(distM[u.x][u.y]+1) ) 
						&& (c2[temp.x][temp.y]!=(distM[u.x][u.y]+1))
						) {
					distM[temp.x][temp.y]=distM[u.x][u.y]+1;
					if(!edge(temp,n,m))
						qm.push(temp);
				}
			}
		}
		bool escaped=false;
		if(!escaped) {
			for(i=1;i<=n;i++) {
				if(distM[i][1]!=-1 && (distM[i][1] < c1[i][1] || distM[i][1]<c2[i][1])) {
					escaped=true;
					break;
				}
				if(distM[i][m]!=-1 && distM[i][m] < c1[i][m] && distM[i][m]<c2[i][m]) {
					escaped=true;
					break;
				}
			}
		}
		if(!escaped) {
			for(i=1;i<=m;i++) {
				if(distM[1][i]!=-1 && (distM[1][i]<c1[1][i] || distM[1][i]<c2[1][i])) {
					escaped=true;
					break;
				}
				if(distM[n][i]!=-1 && (distM[n][i]<c1[n][i] || distM[n][i]<c2[n][i])) {
					escaped=true;
					break;
				}
			}
		}
		if(!escaped)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

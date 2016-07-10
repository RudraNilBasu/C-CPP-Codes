#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
typedef struct cell {
	int x;
	int y;
}cell;
int isValid(cell n)
{
	if(n.x<'a')
		return 0;
	if(n.x>'h')
		return 0;
	if(n.y<1)
		return 0;
	if(n.y>8)
		return 0;
	return 1;
}
int main()
{
	int t;
	cell moves[8];

	moves[0].x=2;
	moves[0].y=1;
	moves[1].x=1;
	moves[1].y=2;
	moves[2].x=2;
	moves[2].y=-1;
	moves[3].x=1;
	moves[3].y=-2;
	moves[4].x=-1;
	moves[4].y=2;
	moves[5].x=-2;
	moves[5].y=1;
	moves[6].x=-2;
	moves[6].y=-1;
	moves[7].x=-1;
	moves[7].y=-2;

	scanf("%d",&t);

	int i,j,k;

	int convert[8][8];
	k=1;
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			convert[i][j]=k++;
		}
	}

	while(t--) {
		char x;
		int y;
		char s1[3],s2[3];
		scanf("%s %s",s1,s2);
		cell start,end;
		start.x=s1[0];
		start.y=s1[1]-'0';
		end.x=s2[0];
		end.y=s2[1]-'0';
		
		int dist[65];
		for(i=0;i<65;i++) {
			dist[i]=-1;
		}

		queue<cell> q;
		q.push(start);
		
		int index=convert[start.x-'a'][start.y-1];
		dist[index]=0;
		while(!q.empty()) {
			cell u=q.front();
			q.pop();

			int srcIndex;
			srcIndex=convert[u.x-'a'][u.y-1];

			for(i=0;i<8;i++) {
				cell temp;
				temp.x=u.x+moves[i].x;
				temp.y=u.y+moves[i].y;
				if( isValid(temp) ) {
					int destIndex;
					destIndex=convert[temp.x-'a'][temp.y-1];
					if( dist[destIndex]==-1 ) {
						dist[destIndex]=dist[srcIndex]+1;
						q.push(temp);
					}
				}
			}
		}
		index=convert[end.x-'a'][end.y-1];
		printf("%d\n",dist[index]);
	}
	return 0;
}

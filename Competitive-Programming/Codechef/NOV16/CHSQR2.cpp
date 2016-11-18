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

int dist(int row, int col, int n)
{
	int c=n/2;
	return abs(row-c)+abs(col-c);
}


/*
int print(int n)
{
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d ",);
		}
	}
}
*/

int main()
{
	int t,n,i,j,k,cnt;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int board[n][n];
		memset(board, 0, sizeof(board));
		i=n/2;
		int st=n-1;
		for(i=n/2;i<n;i++) {
			cnt=1;
			for(k=st;k<n;k++) {
				board[i][k]=cnt++;
			}
			for(k=0;k<st;k++) {
				board[i][k]=cnt++;
			}
			st--;
		}
		cnt=1;
		for(i=0;i<n;i++) {
			board[0][i]=cnt++;
		}
		st=(n/2)-1;
		for(i=1;i<n/2;i++) {
			int cnt=1;
			for(k=st;k<n;k++) {
				board[i][k]=cnt++;
			}
			for(k=0;k<st;k++) {
				board[i][k]=cnt++;
			}
			st--;
		}
		//print(n);
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				printf("%d ",board[i][j]);
			}
			printf("\n");
		}
		/*
		   memset(board, -1, sizeof(board));
		   bool isDone=false;
		   int row=-1;
		   for(i=0;i<n && !isDone;i++) {
		   for(j=0;j<n && !isDone;j++) {
		   if(dist(i,j,n)==n/2 && !isDone) {
		   isDone=true;
		   row=i;
		   break;
		   }
		   }
		   }
		// only one square contains one 
		// rest all -1
		for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
		if(i!=row && dist(i,j,n)>=n/2) {
// fill up with 1-10
}
}
}
*/
}
	return 0;
}


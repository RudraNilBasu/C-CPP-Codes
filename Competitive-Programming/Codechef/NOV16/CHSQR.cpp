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

typedef struct cell {
	int x;
	int y;
}cell;
/*
int maxDist=-1;
bool colFree[401];
int find(int i, int n)
{
	if(i>=n) {
		if(findDist())
	}
}
*/
int n;
int board[401][401];
bool isSafe(int row, int col)
{
	int i;
	// check if not eatable
	// check full row
	// check full col
	for(i=0;i<n;i++) {
		if(board[i][col]==1) {
			return false;
		}
	}
	for(i=0;i<n;i++) {
		if(board[row][i]==1) {
			return false;
		}
	}
	// check if dist<=fk
	int k=(n+0)/2;
	int dist=abs(k-row)+abs(k-col);
	if(dist<n/2)
		return false;
	return true;
}
bool solve(int col)
{
	if(col>=n)
		return true;
	int i;
	for(i=0;i<n;i++) {
		if(isSafe(i,col)) {
			board[i][col]=1;
			if(solve(col+1)) {
				return true;
			}
			board[i][col]=-1;
		}
	}
	return false;
}
void print()
{
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			
			if(board[i][j]==-1) {
				printf("x");
			} else {
				printf("1");
			}
			
			//printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int t,i,j;
	int hash[401];
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		
		if(n==1) {
			printf("1\n");
			continue;
		}
		// L
		if(n==3) {
			printf("3 2 1\n");
			printf("1 3 2\n");
			printf("2 1 3\n");
			continue;
		}
		if(n==5) {
			printf("5 4 3 2 1\n");
			printf("4 3 2 1 5\n");
			printf("1 2 4 5 3\n");
			printf("2 1 5 3 4\n");
			printf("3 5 1 4 2\n");
			continue;
		}
		
		// end of L
		/*
		maxDist=-1;
		memset(colFree, true, sizeof(colFree));
		find(0,n); // current row no
		*/
		// idea 1: f(k)=k/2
		int fk=n/2;
		memset(board, -1, sizeof(board));
		solve(0);
		print();
		/*
		bool found=false;
		while(!found) {
			//
		}
		*/
		int m;
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				if(board[i][j]==1)
					continue;
				memset(hash,0,sizeof(hash));
				//int hash[n]={0};
				for(m=0;m<j;m++) {
					hash[board[i][m]]++;
				}
				for(m=0;m<i;m++) {
					hash[board[m][i]]++;
				}
				for(m=2;m<=n;m++) {
					if(hash[m]==0) {
						board[i][j]=m;
						break;
					}
				}
			}
		}
		//print();
	}
	return 0;
}


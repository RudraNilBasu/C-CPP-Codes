#include<stdio.h>
#include<string.h>
using namespace std;
int ab(int n)
{
	if(n<0) {
		return n*-1;
	}
	return n;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	char board[3][4];
	while(t--) {
		for(i=0;i<3;i++) {
			scanf("%s",board[i]);
		}
		int x,y;
		x=0;
		y=0;
		for(i=0;i<3;i++) {
			for(j=0;j<3;j++) {
				if(board[i][j]=='X') {
					x++;
				} else if(board[i][j]=='O') {
					y++;
				}
			}
		}
		if( (x-y)==0 || (x-y)==1 ) {
		} else {
			printf("no\n");
			continue;
		}
		int win=0;
		char ch;
		for(i=0;i<3;i++) {
			if(board[i][0]==board[i][1] 
					&& board[i][0]==board[i][2] 
					&& board[i][0]!='.') {
				win++;
				ch=board[i][0];
			}
		}
		if(win>1) {
			printf("no\n");
			continue;
		}
		if(win==1 && ch=='X' && (x==y)) {
			printf("no\n");
			continue;
		}
		if(win==1 && ch=='O' && (x>y)) {
			printf("no\n");
			continue;
		}
		int win2=0;
		char ch2;
		for(i=0;i<3;i++) {
			if(board[0][i]==board[1][i] 
					&& board[0][i]==board[2][i] 
					&& board[0][i]!='.') {
				win2++;
				ch2=board[0][i];
			}
		}
		if(win2>1) {
			printf("no\n");
			continue;
		}
		if(win2==1 && ch2=='X' && (x==y)) {
			printf("no\n");
			continue;
		}
		if(win2==1 && ch2=='O' && (x>y)) {
			printf("no\n");
			continue;
		}
		if( board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!='.' ) {
			if(board[0][0]=='O' && (x>y)) {
				printf("no\n");
				continue;
			}
		}
		if( board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!='.' ) {
			if(board[0][2]=='O' && (x>y)) {
				printf("no\n");
				continue;
			}
		}
		printf("yes\n");
	}
	return 0;
}

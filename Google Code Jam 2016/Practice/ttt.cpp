#include<stdio.h>
using namespace std;
char board[5][5];
int main()
{
	int t,test,i,j,flag,k;
	char ch;
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		for(i=0;i<4;i++)
		{
			scanf("%s",board[i]);
		}
		/*
		if(t==633)
		{
			for(i=0;i<4;i++)
			{
				printf("%s\n",board[i]);
			}
		}
		*/
		flag=0;
		k=0;
		for(i=0;i<4 && !flag;i++)
		{
			// checking for row matching
			ch=board[i][0];
			k=0;
			if(ch=='T') ch=board[i][1];
			if(ch=='.') continue;
			for(j=0;j<4;j++)
			{
				if(board[i][j]==ch || board[i][j]=='T')
				{
					k++;
				}
				if(k==4)
				{
					printf("Case #%d: %c won\n",t,ch);
					flag=1;
					break;
				}
			}
		}
		if(!flag)
		{
			// checking for column matching
			for(j=0;j<4 && !flag;j++)
			{
				k=0;
				ch=board[0][j];
				if(ch=='.') continue;
				if(ch=='T') ch=board[1][j];
				for(i=0;i<4;i++)
				{
					if(ch==board[i][j] || board[i][j]=='T')
					{
						k++;
					}
				}
				if(k==4)
				{
					printf("Case #%d: %c won\n",t,ch);
					flag=1;
					break;
				}
			}
			// check left diagonal
			ch=board[0][0];
			if(ch=='T') ch=board[1][1];
			if(!flag && ch!='.' && (ch==board[1][1] || board[1][1]=='T') && (ch==board[2][2] || board[2][2]=='T') && (ch==board[3][3] || board[3][3]=='T'))
			{
				printf("Case #%d: %c won\n",t,ch);
				flag=1;
				//break;
			}
			// check right diagonal
			ch=board[0][3];
			if(ch=='T') ch=board[1][2];
			if(!flag && ch!='.' && (ch==board[1][2] || board[1][2]=='T') && (ch==board[2][1] || board[2][1]=='T') && (ch==board[3][0] || board[3][0]=='T'))
			{
				printf("Case #%d: %c won\n",t,ch);
				flag=1;
				//break;
			}
			int inc=0;
			// checking incomplete condition
			for(i=0;i<4 && !inc && !flag;i++)
			{
				for(j=0;j<4 && !inc;j++)
				{
					if(board[i][j]=='.')
					{
						inc=1;
					}
				}
			}
			if(inc &&!flag)
			{
				printf("Case #%d: Game has not completed\n",t);
			}
			else if(!inc && !flag)
			{
				printf("Case #%d: Draw\n",t);
			}
		}
	}
	return 0;
}

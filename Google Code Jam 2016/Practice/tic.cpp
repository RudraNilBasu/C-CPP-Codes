#include<stdio.h>
using namespace std;
int main()
{
	int t,test,i,j,flag,k;
	char a[5][4];
	char ch;
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		for(i=0;i<4;i++)
		{
			scanf("%s",a[i]);
		}
		flag=0;
		// checking the  row
		for(i=0;i<4 && !flag;i++)
		{
			ch=a[i][0];
			k=0;
			if(ch=='.')
			{
				continue; // if '.' is present, then it is not possible to win
			}
			if(ch=='T')
			{
				ch==a[i][1];
			}
			for(j=0;j<4;j++)
			{
				if(a[i][j]==ch || a[i][j]=='T')
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
		// checking the column
		for(j=0;j<4 && !flag;j++)
		{
			ch=a[0][j];
			k=0;
			if(ch=='.')
			{
				continue;
			}
			if(ch=='T')
			{
				ch=a[1][j];
			}
			for(i=0;i<4;i++)
			{
				if(a[i][j]==ch || a[i][j]=='T')
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
		// checking left diagonal
		if(!flag)
		{
			ch=a[0][0];
			if(ch=='T')
			{
				ch=a[1][1];
			}
			if(ch!='.')
			{
				k=0;
				for(i=0;i<4;i++)
				{
					if(ch==a[i][i] || a[i][i]=='T')
					{
						k++;
					}
				}
				if(k==4)
				{
					printf("Case #%d: %c won\n",t,ch);
					flag=1;
				}
			}
		}
		// checking right diagonal
		if(!flag)
		{
			ch=a[0][3];
			if(ch=='T')
			{
				ch=a[1][2];
			}
			if(ch!='.')
			{
				k=0;
				for(i=0;i<4;i++)
				{
					if(ch==a[i][3-i] || a[i][3-i]=='T')
					{
						k++;
					}
				}
				if(k==4)
				{
					printf("Case #%d: %c won\n",t,ch);
					flag=1;
				}
			}
		}
		// checking for draw or incomplete
		if(!flag)
		{
			int inc=0;
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(a[i][j]=='.')
					{
						inc++;
					}
				}
			}
			if(inc==0)
			{
				printf("Case #%d: Draw\n",t);
			}
			else
			{
				printf("Case #%d: Game has not completed\n",t);
			}
		}
	}
	return 0;
}

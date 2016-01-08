// https://www.codechef.com/problems/DISTCODE
#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,j,count=0;
	char s[10000];
	scanf("%d",&t);
	int a[26][26];
	while(t--)
	{
		count=0;
		for(i=0;i<26;i++)
		{
			for(j=0;j<26;j++)
			{
				a[i][j]=0; // unvisited
			}
		}
		scanf("%s",s);
		for(i=0;i<strlen(s)-1;i++)
		{
			int t1=s[i]-'A';
			int t2=s[i+1]-'A';
			if(a[t1][t2]==0)
			{
				count++;
				a[t1][t2]=1;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

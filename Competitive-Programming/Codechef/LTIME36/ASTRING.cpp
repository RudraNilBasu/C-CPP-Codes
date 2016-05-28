#include<stdio.h>
#include<string.h>
using namespace std;
int pos;
int n; // length of string
char search(char s[], int start,int end)
{
	// returns the smallest string startng from 
	// index 'start' upto index 'length-end'
	// store the pos of the smallest element in pos
	int i;
	char least='z'+1;
	for(i=start;i<=(end);i++)
	{
		if(least>s[i])
		{
			least=s[i];
			pos=i;
		}
	}
	//printf("it is %c\n");
	return least;
}
int main()
{
	int t,i,k,m;
	char s[100002];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		scanf("%d",&k);
		//m=k;
		n=strlen(s);
		int start=0,end=k;
		for(i=1;i<=k;i++)
		{
			printf("%c",search(s,start,n-end));
			start=pos+1;
			end--;
		}
		printf("\n");
	}
	return 0;
}

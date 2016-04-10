#include<stdio.h>
#include<string.h>
using namespace std;
char s[101];
void rev(int pos)
{
	char dummy[101];
	int i,k=0;
	for(i=pos;i>=0;i--)
	{
		if(s[i]=='+')
		{
			dummy[k++]='-';
		}
		else
		{
			dummy[k++]='+';
		}
	}
	for(i=pos+1;i<strlen(s);i++)
	{
		dummy[k++]=s[i];
	}
	dummy[k++]='\0';
	for(i=0;i<strlen(s);i++)
	{
		s[i]=dummy[i];
	}
}
int main()
{
	int t,test,i,steps,hasEnd;
	scanf("%d",&t);
	for(test=1;test<=t;test++)
	{
		scanf("%s",s);
		char curr; // the current character, all characters before are same
		curr=s[0];
		int currpos=0; // the current position of counting 
		// all string before currpos is of same sign
		steps=0;
		hasEnd=0;
		while(!hasEnd) // insert condition
		{
			for(i=1;i<strlen(s);i++)
			{
				//printf("current = %c\n",curr);
				if(curr!=s[i])
				{
					steps++;
					//printf("prev=%s\n",s);
					rev(currpos);
					//printf("Now=%s\n",s);
				}
				currpos=i;
				curr=s[currpos];
			}
			hasEnd=1;
			if(s[currpos]=='-')
			{
				steps++;
			}
		}
		printf("Case #%d: %d\n",test,steps);
	}
	return 0;
}

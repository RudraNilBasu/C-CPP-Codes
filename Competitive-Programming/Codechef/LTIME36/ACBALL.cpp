#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int n,t,i;
	char X[100001];
	char Y[100001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",X);
		scanf("%s",Y);
		n=strlen(X);
		for(i=0;i<n;i++)
		{
			if(X[i]==Y[i])
			{
				if(X[i]=='W')
					printf("B");
				else
					printf("W");
			}
			else if(X[i]!=Y[i])
				printf("B");
		}
		printf("\n");
	}
	return 0;
}

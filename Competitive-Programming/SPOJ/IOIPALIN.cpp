#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define ll long long int

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

int lps(char s[], int n)
{
	int L[n+1][n+1];
	int i,cl,j;
	for(i=0;i<n;i++) {
		L[i][i]=1;
	}
	for(cl=2;cl<=n;cl++) {
		for(i=0;i<n-cl+1;i++) {
			j=i+cl-1;
			if(s[i]==s[j] && cl==2) {
				L[i][j]=2;
			} else if(s[i]==s[j]) {
				L[i][j]=2+L[i+1][j-1];
			} else {
				L[i][j]=max(L[i][j-1],L[i+1][j]);
			}
		}
	}
	return L[0][n-1];
}

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	printf("%d\n",n-lps(s,n));
	return 0;
}


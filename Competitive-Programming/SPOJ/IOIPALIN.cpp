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
	int i,cl;
	for(i=0;i<n;i++) {
		L[i][i]=1;
	}
	for(cl=2;cl<=n;cl++) {
		for(i=0;i<n-i;i++)
	}
}

using namespace std;

int main()
{
	return 0;
}


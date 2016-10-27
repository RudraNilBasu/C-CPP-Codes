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
#define DEBUG(X) cout << (X) << endl;

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

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n][n];
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			a[i][j]=-1;
		}
	}
	int num=n*n;
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>=k-1;j--) {
			a[i][j]=num--;
		}
	}
	int num2=1;
	for(i=0;i<n;i++) {
		for(j=0;j<k-1;j++) {
			a[i][j]=num2++;
		}
	}
	int count=0;
	for(i=0;i<n;i++) {
		count+=a[i][k-1];
	}
	cout<<count<<endl;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}


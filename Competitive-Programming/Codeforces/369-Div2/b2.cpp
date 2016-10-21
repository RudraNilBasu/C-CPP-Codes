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

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

using namespace std;

int main()
{
	int n,i,j,row=-1,col=-1;
	scanf("%d",&n);
	if(n==1) {
		cout << 1 << endl;
		return 0;
	}
	ull a[n][n];
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			cin>>a[i][j];
			if(a[i][j]==0) {
				row=i;
				col=j;
			}
		}
	}
	int rw;
	if(row!=0) {
		rw=0;
	} else {
		rw=1;
	}
	ull mainSum=0;
	for(i=0;i<n;i++) {
		mainSum+=a[rw][i];
	}
	ull rSum=0;
	for(i=0;i<n;i++) {
		rSum+=a[row][i];
	}
	ull cSum=0;
	for(i=0;i<n;i++) {
		cSum+=a[i][col];
	}
	if(cSum!=rSum) {
		printf("-1\n");
		return 0;
	}
	ull x;
	if(mainSum<rSum) {
		printf("-1\n");
		return 0;
	}
	x=mainSum-rSum;
	//cout << x << endl;
	ull d1=0,d2=0;
	a[row][col]=x;
	for(i=0;i<n;i++) {
		ull xSum=0;
		ull ySum=0;
		for(j=0;j<n;j++) {
			xSum+=a[i][j];
			ySum+=a[j][i];
		}
		if(xSum!=mainSum) {
			printf("-1\n");
			return 0;
		}
		if(ySum!=mainSum) {
			printf("-1\n");
			return 0;
		}
		d1+=a[i][i];
		d2+=a[i][n-i-1];
	}
	if(d1!=mainSum || d2!=mainSum) {
		printf("-1\n");
		return 0;
	}
	if(x==0) {
		printf("-1\n");
		return 0;
	}
	cout << x << endl;
	return 0;
}


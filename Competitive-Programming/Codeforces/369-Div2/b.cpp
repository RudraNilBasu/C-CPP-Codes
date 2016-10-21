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
	int n,i,j;
	scanf("%d",&n);
	ll a[n][n];
	int row=-1,col=-1;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			cin >> a[i][j];
			if(a[i][j]==0) {
				row=i;
				col=j;
			}
		}
	}
	if(n==1) {
		cout << "1\n";
		return 0;
	}
	// find sum of all rows
	map<ull,int> mp;
	ull mainSum=0;
	int rw;
	if(row!=0) {
		rw=0;
	} else {
		rw=1;
	}
	for(i=0;i<n;i++) {
		mainSum+=a[rw][i];
	}
	ull sum=0;
	for(i=0;i<n;i++) {
		if(i==row) {
			continue;
		}
		sum=0;
		for(j=0;j<n;j++) {
			sum+=a[i][j];
		}
		mp[sum]++;
		//cout << "hue " + mp[sum] << '\n';
	}
	//cout << mp.size() << endl;
	//cout << "mymap.size() is " << mp.size() << '\n';
	if(mp.size()>1) {
		printf("-1\n");
		return 0;
	}
	map<ull,int> clSum;
	ull cl=0;
	for(i=0;i<n;i++) {
		if(i==col) {
			continue;
		}
		cl=0;
		for(j=0;j<n;j++) {
			cl+=a[j][i];
		}
		clSum[cl]++;
	}
	if(clSum.size()>1) {
		printf("-1\n");
		return 0;
	}
	ull sumd=0;
	if(row!=col) {
		for(i=0;i<n;i++) {
			sumd+=a[i][i];
		}
		if(sumd!=mainSum) {
			printf("-1\n");
			return 0;
		}
	}
	if(row+col!=n-1) {
		sumd=0;
		for(i=0;i<n;i++) {
			sumd+=a[i][n-i-1];
		}
		if(sumd!=mainSum) {	
			printf("-1\n");
			return 0;
		}
	}
	ull nsum=0;
	for(i=0;i<n;i++) {
		nsum+=a[row][i];
	}
	ull x=mainSum-nsum;
	cout << x << endl;
	return 0;
}


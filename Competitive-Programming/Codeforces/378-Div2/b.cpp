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

typedef struct node {
	int left;
	int right;
}node;

int abs(int x)
{
	if(x>=0)
		return x;
	return -1*x;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	node a[n];
	int L=0,R=0;
	for(i=0;i<n;i++) {
		scanf("%d %d",&a[i].left, &a[i].right);
		L+=a[i].left;
		R+=a[i].right;
	}
	int _l=L;
	int _r=R;
	int max=abs(_l-_r);
	//cout<<max<<endl;
	int maxCol=-1;
	int x;
	for(i=0;i<n;i++) {
		_l=L;
		_r=R;
		_l-=a[i].left;
		_r-=a[i].right;
		_l+=a[i].right;
		_r+=a[i].left;
		x=abs(_l-_r);
		if(x>max) {
			max=x;
			maxCol=i;
		}
	}
	maxCol++;
	printf("%d\n",maxCol);
	//cout<<max<<endl;
	return 0;
}


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
#define SWAP(A,B) (A)=((A)+(B))-((B)=(A))

#define PI 3.14159265
//#define DEBUG(X) cout << (X) << endl;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define DEBUGL(x) std::cerr << "In " << __FILE__ << " at line " << __LINE__ << #x << ' = ' << x << std::endl;

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
	int l;
	int r;
}node;

int n,m,k;
//int c[200001];

int calc(int c[], int index, node qr[])
{
	if(index==m)
		return 0;
	int l,r,i;
	l=qr[index].l;
	r=qr[index].r;
	if(c[l-1]==c[r-1]) {
		return calc(c, index+1, qr);
	} else {
		
		int t[n];
		for(i=0;i<n;i++) {
			t[i]=c[i];
		}
		t[l-1]=t[r-1];
		int x=1+calc(t,index+1, qr);
		t[l-1]=c[l-1];
		t[r-1]=c[l-1];
		int y=1+calc(t,index+1, qr);
		return min(x,y);
		
		/*
		int x_l,x_r;
		x_l=c[l-1];
		x_r=c[r-1];
		c[l-1]=c[r-1];
		int x=1+calc(c,index+1,qr);
		c[l-1]=x_l;
		c[r-1]=c[l-1];
		int y=1+calc(c,index+1,qr);
		return min(x,y);
		*/
	}
}

int main()
{
	//int n,m,k;
	cin>>n>>m>>k;
	int c[n];
	int hash[n+1];
	memset(hash, 0, sizeof(hash));
	int i;
	for(i=0;i<n;i++) {
		cin>>c[i];
	}
	node qr[m];
	int l,r;
	for(i=0;i<m;i++) {
		cin>>l>>r;
		qr[i].l=l;
		qr[i].r=r;
	}
	cout<<calc(c,0,qr)<<endl;
	return 0;
}


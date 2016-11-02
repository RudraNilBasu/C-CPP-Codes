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

typedef struct tree {
	ll _2; // factors of 2
	ll _5; // factors of 5
}tree;

// Editorial - https://discuss.codechef.com/questions/86038/bgqrs-unofficial-editorial
// Sol1 = https://www.codechef.com/viewsolution/11759211
// Sol2 = https://www.codechef.com/viewsolution/11791948

#define MAXN 400005

tree st[MAXN];
ll lazy[MAXN];

tree calc(ll n)
{
	ll m=n;
	tree q;
	ll _2=0;
	ll _5=0;
	while(m>0 && m%2==0) {
		_2++;
		m/=2;
	}
	m=n;
	while(m>0 && m%5==0) {
		_5++;
		m/=5;
	}
	q._2=_2;
	q._5=_5;
	return q;
}

tree query(int ss, int se, int qs, int qe, int node)
{
	// check lazy
	if()
}

void replaceUtil(int ss, int se, int qs, int qe, tree q, int stIndex)
{
	// check lazy things
	// out of range
	if(ss>qe||se<qs) {
		return;
	}
	// fully in range
	if(ss>=qs && se<=qe) {
		st[stIndex]._2=q._2*(se-ss+1);
		st[stIndex]._5=q._5*(se-ss+1);
		st[stIndex]._2+=(div[se-qs+1]._2-div[ss-qs]._2);
		st[stIndex]._5+=(div[se-qs+1]._5-div[ss-qs]._5);
		// lazy check
		return;
	}
	int mid=(ss+se)/2;
	int left=2*stIndex+1;
	int right=left+1;
	replaceUtil(ss,mid,qs,qe,q,left);
	replaceUtil(mid+1,se,qs,qe,q,right);
	st[stIndex]._2=st[left]._2+st[right]._2;
	st[stIndex]._5=st[left]._5+st[right]._5;
	return;
}

void replace(int l, int r, tree x)
{
	replaceUtil(0,n-1,l,r,x,0);
}

void multUtil(int ss, int se, int qs, int qe, tree q, int stIndex)
{
	// if lazy checking
	if(ss>qe || se<qs ) {
		return ;
	}
	if(ss>=qs && se<=qe) {
		// within the segment
		st[stIndex]._2+=q._2*(se-ss+1);
		st[stIndex]._5+=q._5*(se-ss+1);
		// lazy stufs
		return ;
	}
	int mid=(ss+se)/2;
	int left=2*stIndex+1;
	int right=left+1;
	multUtil(ss,mid,qs,qe,q,left);
	multUtil(mid+1,se,qs,qe,q,right);
	st[stIndex]._2=st[left]._2+st[right]._2;
	st[stIndex]._5=st[left]._5+st[stIndex]._5;
	return ;
}

void mult(int l, int r, tree x)
{
	// multiply all elements of l to r by x
	multUtil(0,n-1,l,r,x,0);
}

int constructUtil(int a[], int n, int ss, int se, int sIndex)
{
	if(ss>se) {
		return 0;
	}
	if(ss==se) {
		st[sIndex]=calc(a[ss]);
		// update lazy things
		return 0;
	}
	int mid=(ss+se)/2;
	constructUtil(a,n,ss,mid,sIndex*2+1);
	constructUtil(a,n,mid+1,se,sIndex*2+2);
	int left=sIndex*2+1;
	int right=left+1;
	st[sIndex]._2=st[left]._2+st[right]._2;
	st[sIndex]._5=st[left]._5+st[right]._5;
	// update lazy things
	// check if left and right are correct or not
	return 0;
}

int construct(int a[], int n)
{
	constructUtil(a,n,0,n-1,0);
}

int main()
{
	int t,n,m,i,id,l,r;
	ll x,y;
	ll count=0;
	scanf("%d",&t);
	tree q;
	while(t--) {
		count=0;
		for(i=0;i<MAXN;i++) {
			tree[i]=0;
			lazy[i]=0;
		}
		scanf("%d %d",&n,&m);
		int a[n];
		for(i=0;i<n;i++) {
			scanf("%d",a+i);
		}
		construct(a,n);
		while(m--) {
			scanf("%d",&id);
			if(id==1) {
				scanf("%d %d %lld",&l,&r,&x);
				mult(l-1,r-1,calc(x));
			} else if(id==2) {
				scanf("%d %d %d",&l,&r,&y);
				replace(l-1,r-1,calc(x));
			} else if(id==3) {
				scanf("%d %d",&l,&r);
			}
		}
	}
	return 0;
}


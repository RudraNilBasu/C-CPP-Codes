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

int n;

#define div div_1

typedef struct tree {
	ll _2; // factors of 2
	ll _5; // factors of 5
}tree;

typedef struct lazytree {
	int state;
	int _2;
	int _5;
	tree q;
	ll l;
}lazytree;

// Editorial - https://discuss.codechef.com/questions/86038/bgqrs-unofficial-editorial
// Sol1 = https://www.codechef.com/viewsolution/11759211
// Sol2 = https://www.codechef.com/viewsolution/11791948

#define MAXN 400005

tree div[100010];
tree st[MAXN];
lazytree lazy[MAXN];

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

tree query(int ss, int se, int qs, int qe, int stIndex)
{
	// check lazy
	if(ss>qe||se<qs) {
		// not possible
		tree x;
		x._2=0;
		x._5=0;
		return x;
	}
	if(ss>=qs && se<=qe) {
		return st[stIndex];
	}
	int mid=(ss+se)/2;
	int left=2*stIndex;
	int right=left+1;
	tree p=query(ss,mid,qs,qe,left);
	tree q=query(mid+1,se,qs,qe,right);
	p._2=p._2+q._2;
}

void replaceUtil(int ss, int se, int qs, int qe, tree q, int stIndex)
{
	// check lazy things
	if(lazy[stIndex].state==1) {
		if(lazy[stIndex].l!=-1) {
			st[stIndex]._2 = lazy[stIndex].q._2*(se-ss+1);
			st[stIndex]._5 = lazy[stIndex].q._5*(se-ss+1);
			st[stIndex]._2 += (div[se-lazy[stIndex].l+1]._2-div[ss-lazy[stIndex].l]._2);
			st[stIndex]._5 += (div[se-lazy[stIndex].l+1]._5-div[ss-lazy[stIndex].l]._5);
			if(ss!=se)
			{
				int left=2*stIndex;
				int right=left+1;
				lazy[left].l = lazy[stIndex].l;
				lazy[right].l = lazy[stIndex].l;
				lazy[left].q= lazy[stIndex].q;
				lazy[right].q = lazy[stIndex].q;
				lazy[right].state =1;
				lazy[left].state =1;
				lazy[left]._2 = 0;
				lazy[left]._5 = 0;
				lazy[right]._2 = 0;
				lazy[right]._5 = 0;
			}
			lazy[stIndex].l=-1;
		}
		st[stIndex]._2=lazy[stIndex]._2*(se-ss+1);
		st[stIndex]._5=lazy[stIndex]._5*(se-ss+1);
		if(ss!=se) {
			int left=2*stIndex;
			int right=left+1;
			lazy[left]._2+=lazy[stIndex]._2;
			lazy[left]._5+=lazy[stIndex]._5;
			lazy[right]._2+=lazy[stIndex]._2;
			lazy[right]._5+=lazy[stIndex]._5;
			lazy[left].state=1;
			lazy[right].state=1;
		}
		//lazy[stIndex].l=-1;
		lazy[stIndex].state=0;
		lazy[stIndex]._2=0;
		lazy[stIndex]._5=0;
	}
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
		if(ss!=se) {
			int left=2*stIndex;
			int right=left+1;
			lazy[left].l=qs;
			lazy[left].q=q;
			lazy[left].state=1;
			lazy[left]._2=0;
			lazy[left]._5=0;
			lazy[right].l=qs;
			lazy[right].q=q;
			lazy[right].state=1;
			lazy[right]._2=0;
			lazy[right]._5=0;
		}
		return;
	}
	int mid=(ss+se)/2;
	int left=2*stIndex;
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
	if(lazy[stIndex].state==1) {
		if(lazy[stIndex].l!=-1) {
			st[stIndex]._2=lazy[stIndex].q._2*(se-ss+1);
			st[stIndex]._5=lazy[stIndex].q._5*(se-ss+1);
			st[stIndex]._2+=(div[se-lazy[stIndex].l+1]._2-div[ss-lazy[stIndex].l]._2);
			st[stIndex]._5+=(div[se-lazy[stIndex].l+1]._5-div[ss-lazy[stIndex].l]._5);
			if(ss!=se) {
				int left=2*stIndex;
				int right=left+1;
				lazy[left].l=lazy[stIndex].l;
				lazy[right].l=lazy[stIndex].l;
				lazy[left].q=lazy[stIndex].q;
				lazy[right].q=lazy[stIndex].q;
				lazy[left].state=1;
				lazy[right].state=1;
				lazy[left]._2=0;
				lazy[left]._5=0;
				lazy[right]._2=0;
				lazy[right]._5=0;
			}
			lazy[stIndex].l=-1;
		}
		//
		int left=2*stIndex;
		int right=left+1;
		st[stIndex]._2=lazy[stIndex]._2*(se-ss+1);
		st[stIndex]._5=lazy[stIndex]._5*(se-ss+1);
		if(ss!=se) {
			// lazy to children
			lazy[left]._2+=lazy[stIndex]._2;
			lazy[left]._5+=lazy[stIndex]._5;
			lazy[right]._2+=lazy[stIndex]._2;
			lazy[right]._5+=lazy[stIndex]._5;
			lazy[left].state=1;
			lazy[right].state=1;
		}
		lazy[stIndex].state=0;
		lazy[stIndex]._2=0;
		lazy[stIndex]._5=0;
	}
	if(ss>qe || se<qs ) {
		return ;
	}
	if(ss>=qs && se<=qe) {
		// within the segment
		st[stIndex]._2+=q._2*(se-ss+1);
		st[stIndex]._5+=q._5*(se-ss+1);
		if(ss!=se) {
			// lazy stufs
			int left=2*stIndex;
			int right=left+1;
			lazy[left].state=1;
			lazy[left]._2+=q._2;
			lazy[left]._5+=q._5;
			lazy[right].state=1;
			lazy[right]._2+=q._2;
			lazy[right]._5+=q._5;
		}
		return ;
	}
	int mid=(ss+se)/2;
	int left=2*stIndex;
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
		lazy[sIndex].state=0;
		lazy[sIndex]._2=0;
		lazy[sIndex]._5=0;
		int left=2*sIndex;
		int right=left+1;
		lazy[left].state=0;
		lazy[left]._2=0;
		lazy[left]._5=0;
		lazy[right].state=0;
		lazy[right]._2=0;
		lazy[right]._5=0;
		lazy[sIndex].l=-1;
		lazy[left].l=-1;
		lazy[right].l=-1;
		return 0;
	}
	int mid=(ss+se)/2;
	constructUtil(a,n,ss,mid,sIndex*2+1);
	constructUtil(a,n,mid+1,se,sIndex*2+2);
	int left=sIndex*2;
	int right=left+1;
	st[sIndex]._2=st[left]._2+st[right]._2;
	st[sIndex]._5=st[left]._5+st[right]._5;
	lazy[sIndex].state=0;
	lazy[sIndex]._2=0;
	lazy[sIndex]._5=0;
	lazy[sIndex].l=-1;
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
	//lazytree xx[5];xx[0]._2=0;
	int t,m,i,id,l,r;
	ll x,y;
	ll count=0;
	scanf("%d",&t);
	tree q;
	ll ans;
	div[0]._2=0;
	div[0]._5=0;
	for(i=1;i<100010;i++) {
		int _2=0,_5=0;
		int num=i;
		if(num%2==0) {
			_2=1;
			num/=2;
		} else if(num%5==0) {
			_5=1;
			num/=5;
		}
		div[i]._2=div[num]._2+_2;
		div[i]._5=div[num]._5+_5;
	}
	for(i=1;i<=100010;i++)
	{
		div[i]._2 = div[i]._2+div[i-1]._2;
		div[i]._5 = div[i]._5+div[i-1]._5;
	}
	// one more thing
	while(t--) {
		count=0;
		ans=0;
		/*
		for(i=0;i<MAXN;i++) {
			st[i]=0;
			lazy[i].state=0;
		}
		*/
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
				scanf("%d %d %lld",&l,&r,&y);
				replace(l-1,r-1,calc(x));
			} else if(id==3) {
				scanf("%d %d",&l,&r);
				tree q=query(0,n-1,l-1,r-1,0);
				ans+=min(q._2,q._5);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


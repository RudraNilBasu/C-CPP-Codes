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

float min(float a, float b)
{
	if(a<=b)
		return a;
	return b;
}

float min3(float a, float b, float c)
{
	return min( a, min(b, c));
}

typedef struct rect{
	ll a;
	ll b;
	ll c;
}rect;


float rad(ll a, ll b, ll c)
{
	return min3((float)a/2, (float)b/2, (float)c/2);
}

typedef struct area {
	ull a1;
	ull a2;
	ull a3;
}area;

bool check(area a, area b)
{
	if( a.a1==b.a1 || a.a1==b.a2 || a.a1==b.a3)
		return true;
	if( a.a2==b.a1 || a.a2==b.a2 || a.a2==b.a3)
		return true;
	if( a.a3==b.a1 || a.a3==b.a2 || a.a3==b.a3)
		return true;
	return false;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	rect a[n];
	area ar[n];
	float minRad=-1;
	int x=-1,y=-1;
	ll tr[3];
	float r;
	for(i=0;i<n;i++) {
		cin>>a[i].a>>a[i].b>>a[i].c;
		tr[0]=a[i].a;
		tr[1]=a[i].b;
		tr[2]=a[i].c;
		sort(tr,tr+3);
		a[i].a=tr[0];
		a[i].b=tr[1];
		a[i].c=tr[2];
		r=rad(a[i].a, a[i].b, a[i].c);
		if(r>minRad) {
			x=i;
			minRad=r;
		}
		ar[i].a1=a[i].a*a[i].b;
		ar[i].a2=a[i].b*a[i].c;
		ar[i].a3=a[i].a*a[i].c;
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(i==j) {
				continue;
			}
			if(!check(ar[i],ar[j])) {
				continue;
			}
			if(a[i].a==a[j].a && a[i].b==a[j].b && a[i].c!=a[j].c) {
				r=rad(a[i].a, a[i].b, a[i].c+a[j].c);
				if(r>minRad) {
					x=i;
					y=j;
					minRad=r;
				}
			}
			else if(a[i].a!=a[j].a && a[i].b==a[j].b && a[i].c==a[j].c) {
				r=rad(a[i].a+a[j].a, a[i].b, a[i].c);
				if(r>minRad) {
					x=i;
					y=j;
					minRad=r;
				}
			}
			if(a[i].a==a[j].a && a[i].b!=a[j].b && a[i].c==a[j].c) {
				r=rad(a[i].a, a[i].b+a[j].b, a[i].c);
				if(r>minRad) {
					x=i;
					y=j;
					minRad=r;
				}
			}
			if(a[i].a==a[j].a && a[i].b==a[j].b && a[i].c==a[j].c) {
				r=rad(a[i].a, a[i].b, a[i].c+a[j].c);
				if(r>minRad) {
					x=i;
					y=j;
					minRad=r;
				}
				r=rad(a[i].a, a[i].b+a[j].b, a[i].c);
				if(r>minRad) {
					x=i;
					y=j;
					minRad=r;
				}
				r=rad(a[i].a+a[j].a, a[i].b, a[i].c);
				if(r>minRad) {
					x=i;
					y=j;
					minRad=r;
				}
			}
		}
	}
	if(y==-1) {
		printf("1\n%d\n",x+1);
	} else {
		printf("2\n%d %d\n",x+1,y+1);
	}
	return 0;
}


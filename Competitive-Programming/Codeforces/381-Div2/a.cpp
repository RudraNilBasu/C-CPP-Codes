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

ll a[4];

ll min(ll a, ll b)
{
	if(a<=b)
		return a;
	return b;
}
ll min3(ll a, ll b, ll c)
{
	return min(a,min(b,c));
}

ll calc2(ll n)
{
	DEBUG(n)
	if((n)%4==0) {
		return 0;
	}
	//if()
	return min3(
		a[1]+calc2(n+1),
		a[2]+calc2(n+2),
		a[3]+calc2(n+3)
			);
}
ll calc(ll n)
{
	if(n%4==0)
		return 0;
	ll mn=min3(a[1],a[2],a[3]);
	int k=4-(n%4);
	if(k==0)
		return 0;
	if(a[k]==mn)
		return mn;
	/*
	return min3(
		a[1]+calc(n+1),
		a[2]+calc(n+2),
		a[3]+calc(n+3)
			);
	*/
	if(a[1]==mn && a[2]!=mn && a[3]!=mn) {
		return mn+calc(n+1);
	} else if(a[2]==mn && a[1]!=mn && a[2]!=mn) {
		return mn+calc(n+2);
	} else if(a[3]==mn && a[1]!=mn && a[2]!=mn) {
		return mn+calc(n+3);
	}
	if(a[1]==mn) {
		return min(a[2]+calc(n+2),a[3]+calc(n+3));
	} else if(a[2]==mn) {
		return min(a[1]+calc(n+1), a[3]+calc(n+3));
	} else {
		return min(a[1]+calc(n+1), a[2]+calc(n+2));
	}
}
#include<limits.h>
int main()
{
	ll n;
	//int k;
	cin>>n>>a[1]>>a[2]>>a[3];
	//k=4-(n%4);
	int i,j,k;
	ll ans=LLONG_MAX;
	for(i=0;i<=100;i++) {
		for(j=0;j<=100;j++) {
			for(k=0;k<=100;k++) {
				if((n+i+j*2+k*3)%4==0) {
					ans=min(ans,(a[1]*i)+(a[2]*j)+(a[3]*k));
				}
			}
		}
	}
	cout<<ans<<endl;
	//cout<<calc(n)<<endl;
	//DEBUG(k)
	return 0;
}


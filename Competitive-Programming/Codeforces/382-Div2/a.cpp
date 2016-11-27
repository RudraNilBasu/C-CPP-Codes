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

int abs(int n)
{
	if(n>=0)
		return n;
	return -1*n;
}

int main()
{
	int n,k,i,G,T;
	scanf("%d %d",&n,&k);
	char a[n+1];
	scanf("%s",a);
	for(i=0;i<n;i++) {
		if(a[i]=='G') {
			G=i;
		} else if(a[i]=='T'){
			T=i;
		}
	}
	int fr=0,bck=0;
	// going forward
	for(i=G;i<n;i+=k) {
		if(a[i]=='#') {
			fr==-1;
			break;
		}
		if(a[i]=='T') {
			fr=1;
			break;
		}
	}
	// back
	for(i=G;i>=0;i-=k) {
		if(a[i]=='#') {
			bck=-1;
			break;
		}
		if(a[i]=='T') {
			bck=1;
			break;
		}
	}
	if(fr==1||bck==1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	/*
	int dist=abs(G-T);
	//cout<<G<<" "<<T<<" "<<dist<<endl;
	if(dist%k==0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	*/
	return 0;
}


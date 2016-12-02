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

int main()
{
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++) {
		cin>>a[i];
	}
	int flag=0, cpn=0;
	for(i=0;i<n;i++) {
		if(cpn) {
			if(a[i]==0) {
				flag=1;
				break;
			}
			a[i]--;
			cpn=0;
		}
		if(a[i]&1) {
			// odd
			cpn=1;
		} else {
			// even
		}
	}
	if(flag || cpn) {
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
	}
	return 0;
}


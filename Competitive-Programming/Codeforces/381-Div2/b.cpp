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
	int total;
	int l;
	int r;
}node;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	int freq[n];
	memset(freq, 0, sizeof(freq));
	int i;
	for(i=0;i<n;i++) {
		cin>>a[i];
	}
	int l,r;
	int j;
	for(i=0;i<m;i++) {
		cin>>l>>r;
		int sum=0;
		for(j=l-1;j<r;j++) {
			sum+=a[j];
		}
		if(sum>=0) {
			// include this
			for(j=l-1;j<r;j++) {
				freq[j]++;
			}
		}
	}
	ll ans=0;
	for(i=0;i<n;i++) {
		ans+=(freq[i]*a[i]);
	}
	cout<<ans<<endl;
	return 0;
}


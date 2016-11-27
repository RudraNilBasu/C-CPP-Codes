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

#define MAXN 2000000001

//bool primes[MAXN];
/*
vector<int> primes[MAXN];

void pre()
{
	memset(primes, 1, sizeof(primes));
	primes[1]=0;
	ll i,j;
	for(i=2;i<MAXN;i++) {
		if(primes[i]) {
			for(j=i+i;j<MAXN;j+=i) {
				primes[j]=0;
			}
		}
	}
}
*/

ll findLargestFactor(ll n)
{
	ll i;
	for(i=n-1;i>=1;i--) {
		if(n%i==0)
			return i;
	}
}

ll findLastPrime(ll n)
{
	ll i;
	for(i=n;i>=2;i--) {
		/*
		if(primes[i])
			return i;
		*/
		if(findLargestFactor(i)==1)
			return i;
	}
}

ll min(ll a, ll b)
{
	if(a<=b)
		return a;
	return b;
}

ll find(ll n)
{
	/*
	if(primes[n])
		return 1;
	*/
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	int f=findLargestFactor(n);
	if(f==1) {
		return 1;
	}
	int p=findLastPrime(n);
	cout<<f<<" "<<p<<endl;
	return min(f,p+find(n-p));
}

int main()
{
	//pre();
	ll n;
	cin>>n;
	cout<<find(n)<<endl;
	return 0;
}


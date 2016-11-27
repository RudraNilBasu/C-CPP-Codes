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

int main()
{
	ull n,cnt=0;
	cin>>n;
	float ans;
	ans=log2(n);
	int x=(int)ans;
	if((ans-(int)ans)!=0) {
		x++;
	}
	cout<<x<<endl;
	/*
	while(n>1) {
		if(n%2) {
			// n is odd
			n/=2;
			n++;
		} else {
			// n is even
			n/=2;
		}
		cnt++;
	}
	cout<<cnt<<endl;
	*/
	return 0;
}


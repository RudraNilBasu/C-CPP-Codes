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

int main()
{
	ull d,b,s;
	ull remain=0;
	cin>>b>>d>>s;
	if(d==b && b==s) {
		cout<<"0\n";
		return 0;
	}
	if( b==d && b>s) {
		remain=b-1-s;
		cout<<remain<<endl;
		return 0;
	}
	if(b==d) {
		if(s>b) {
			remain = 2*(s-1-b);
		} else if(s<b) {
			remain = b-1-s;
		}
		cout<<remain<<endl;
		return 0;
	} else if(b==s) {
		if(d>b) {
			remain=2*(d-1-s);
		} else if(d<b) {
			remain=b-1-d;
		}
		cout<<remain<<endl;
		return 0;
	} else if(s==d) {
		if(b>s) {
			remain=2*(b-1-s);
		} else if(b<s) {
			remain=s-1-b;
		}
		cout<<remain<<endl;
		return 0;
	} else {
		// all are diff
		// make smallest = 2nd largest = largest -1
		if( b>d && b>s) {
			remain=(b-1-s)+(b-1-d);
		} else if(d>b && d>s) {
			remain=(d-1-s)+(d-1-b);
		} else if(s>b && s>d) {
			remain=(s-1-b)+(s-1-d);
		}
		cout<<remain<<endl;
		return 0;
	}
	return 0;
}


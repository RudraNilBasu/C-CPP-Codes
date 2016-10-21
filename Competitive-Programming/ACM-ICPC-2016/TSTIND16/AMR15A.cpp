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
	int n,i;
	inpd(n);
	int a[n];
	int odd=0;
	int even=0;
	for(i=0;i<n;i++) {
		inpd(a[i]);
		if(a[i]&1) {
			// odd
			odd++;
		} else {
			even++;
		}
	}
	if(even>odd) {
		printf("READY FOR BATTLE\n");
	} else {
		printf("NOT READY\n");
	}
	return 0;
}


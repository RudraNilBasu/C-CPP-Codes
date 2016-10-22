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
	int t,x1,y1,x2,y2;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1!=x2 && y1!=y2) {
			printf("sad\n");
			continue;
		}
		if(x1==x2) {
			if(y1>y2) {
				printf("down\n");
			} else {
				printf("up\n");
			}
		} else if(y1==y2) {
			if(x1>x2) {
				printf("left\n");
			} else {
				printf("right\n");
			}
		}
	}
	return 0;
}


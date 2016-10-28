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
	ull n,a,b,c;
	cin>>n>>a>>b>>c;
	if(a<=(b-c)||n<b) {
		cout<<(ull)(n/a)<<endl;
	} else {
		// spend with b while you still can
		ull k=(n-c)/(b-c); // bought k bottles
		n-=k*(b-c); // cost left
		k+=(n/a);
		cout<<k<<endl;
	}
	return 0;
	//cout<<findMax(n,a,b,c)<<endl;
	/*
	ull ans=0,cost=n;
	if(a>b) {
		// we have to use b
		ans+=(cost-b)/(b-d);
	} else {
		//ans+=
	}
	*/
	/*
	while(cost>=a || cost>=b) {
		if(cost<a && cost<b) {
			break;
			//return 0;
		}
		if(cost>=a && cost<b) {
			ans++;
			cost-=a;
			//return 1+findMax(cost-a, a, b, c);
		} else if(cost<a && cost>=b) {
			ans++;
			cost-=(b-c);
			//return 1+findMax(cost-(b-c), a, b, c);
		} else {
			ans++;
			if(a>(b-c)) {
				cost-=(b-c);
			} else {
				cost-=a;
			}
		}
	}
	*/
	//cout<<ans<<endl;
	return 0;
}


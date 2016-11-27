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
	int n,n1,n2,i;
	float ans=0.0f;
	scanf("%d %d %d",&n,&n1,&n2);
	int a[n];
	for(i=0;i<n;i++) {
		scanf("%d",a+i);
	}
	sort(a,a+n);
	if(n1>n2) {
		int temp=n2;
		n2=n1;
		n1=temp;
	}
	// take the highest n1 elements
        int cnt=0,sum=0,pos=-1;
	for(i=n-1;i>=0;i--) {
		cnt++;
		sum+=a[i];
		if(cnt==n1) {
			pos=i;
			break;
		}
	}
	ans=(sum*1.0)/n1;
	sum=0;
	cnt=0;
	for(i=pos-1;i>=0;i--) {
		cnt++;
		sum+=a[i];
		if(cnt==n2) {
			break;
		}
	}
	ans+=(sum*1.0)/n2;
	printf("%0.8f\n",ans);
	return 0;
}


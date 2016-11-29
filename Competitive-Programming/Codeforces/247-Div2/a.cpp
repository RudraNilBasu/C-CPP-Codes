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
	int a1,a2,a3,a4;
	int a[5];
	//string s;
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	char s[100001];
	scanf("%s",s);
	int i,x;
	ll sum=0;
	for(i=0;i<strlen(s);i++) {
		x=s[i]-'0';
		sum+=a[s[i]-'0'];
	}
	cout<<sum<<endl;
	return 0;
}


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
	int t,i,flag;
	//char s[100001];
	scanf("%d",&t);
	while(t--) {
		/*
		scanf("%s",s);
		flag=0;
		char next='I';
		for(i=0;i<strlen(s);i++) {
			
		}
		*/
		string s;
		string str="IEM";
		cin>>s;
		flag=0;
		while(s.length()!=0) {
			std::string::size_type i = s.find(str);
			if (i != std::string::npos)
				   s.erase(i, str.length());
			else {
				flag=1;
				break;
			}
		}
		if(flag) {
			cout<<"No\n";
		} else {
			cout<<"Yes\n";
		}
	}
	return 0;
}


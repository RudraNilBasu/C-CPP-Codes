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

char s[101];

typedef struct node {
	char ch;
	int dist;
}node;

int dist1(char src, char dest)
{
	// clockwise
	int i=0;
	char curr=src;
	while(1) {
		if(curr==dest) {
			return i;
		}
		i++;
		if(curr=='z') {
			curr='a';
		} else {
			curr++;
		}
	}
}

int dist2(char src, char dest)
{
	// anti
	int i=0;
	char curr=src;
	while(1) {
		if(curr==dest) {
			return i;
		}
		i++;
		if(curr=='a') {
			curr='z';
		} else {
			curr--;
		}
	}
}

int calc(int pos, int len, char pointer_char)
{
	if(pos>=len) {
		return 0;
	}
	int dist_cl,dist_acl;
	dist_cl=dist1(pointer_char, s[pos]);
	dist_acl=dist2(pointer_char, s[pos]);
	//cout<<pointer_char<<' '<<dist_cl<<' '<<dist_acl<<endl;
	return min(dist_cl,dist_acl)+calc(pos+1, len, s[pos]);
}

int main()
{
	scanf("%s",s);
	int n=strlen(s);
	printf("%d\n",calc(0,n,'a'));
	return 0;
}


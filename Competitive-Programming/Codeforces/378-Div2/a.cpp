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

bool isVowel(char ch)
{
	if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
		return true;
	return false;
}

int main()
{
	char str[101];
	scanf("%s",str);
	int i,n=strlen(str);
	int pos=-1; // position of last occured vowel;
	int maxDist=-1; // max distance between 2 vowels
	int dist;
	for(i=0;i<n;i++) {
		if(isVowel(str[i])) {
			dist=i-pos;
			if(dist>maxDist) {
				maxDist=dist;
			}
			pos=i;
		}
	}
	dist=n-pos;
	if(dist>maxDist) {
		maxDist=dist;
	}
	printf("%d\n",maxDist);
	return 0;
}


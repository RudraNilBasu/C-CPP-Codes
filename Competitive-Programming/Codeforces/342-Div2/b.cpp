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
	char ai[100002];
	char ph[32];
	int i,j,k,flag,count;
	scanf("%s",ai);
	scanf("%s",ph);
	count=0;
	int len_ai=strlen(ai);
	int len_ph=strlen(ph);
	for(i=0;i<len_ai-len_ph+1;i++) {
		if(ai[i]==ph[0]) {
			flag=0;
			for(k=0;k<len_ph;k++) {
				if(k>=len_ph || (i+k)>=len_ai) {
					flag=1;
					break;
				}
				if(ph[k]!=ai[i+k]) {
					flag=1;
					break;
				}
			}
			if(!flag) {
				count++;
				i+=len_ph-1;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}


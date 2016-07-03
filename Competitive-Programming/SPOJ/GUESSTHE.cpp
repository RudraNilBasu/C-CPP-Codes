/*
 Find LCM of all (i+1)'s for which str[i]='Y'
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#define ll long long int
using namespace std;
ll gcd(ll a, ll b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}
ll lcm(ll a, ll b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	char s[20];
	while(1) {
		scanf("%s",s);
		if(s[0]=='*')
			break;
		int i,j;
		vector<int> g;
		for(i=0;i<strlen(s);i++) {
			if(s[i]=='Y') {
				g.push_back(i+1);
			}
		}
		ll ans;
		if(g.size()==0) {
			printf("-1\n");
			continue;
		}  else {
			ans=g[0];
			for(i=1;i<g.size();i++) {
				ans=lcm(ans,g[i]);
			}
		}
		int flag=0;
		for(i=0;i<strlen(s);i++) {
			if(s[i]=='N') {
				if(ans%(i+1)==0) {
					flag=1;
					break;
				}
			}
		}
		if(flag) {
			printf("-1\n");
		} else {
			printf("%lld\n",ans);
		}
	}
	return 0;
}

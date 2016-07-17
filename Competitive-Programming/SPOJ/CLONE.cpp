#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j;
	while(1) {
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) {
			break;
		}
		map<string,int> mp;
		string s[n];
		for(i=1;i<=n;i++) {
			cin >> s[i-1];
			mp[s[i-1]]++;
		}
		int rep[n];
		map<int,int> freq;
		map<string,int>::iterator it;
		for( it=mp.begin(); it!=mp.end();it++  ) {
			freq[it->second]++;
		}
		for(i=1;i<=n;i++) {
			printf("%d\n",freq[i]);
		}
	}
}

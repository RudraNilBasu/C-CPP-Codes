#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;
		int k,n,i,count;
		n=s.length();
		count=0;
		for(k=1;k<=n-1;k++) {
			map<string, int> hash;
			for(i=0;i<=n-k;i++) {
				string s2=s.substr(i,k);
				sort(s2.begin(),s2.end());
				if(hash[s2]>0) {
					count+=hash[s2];
				}
				hash[s2]++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

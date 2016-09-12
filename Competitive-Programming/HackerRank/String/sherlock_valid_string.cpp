#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

#define ll long long int

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

using namespace std;

int main()
{
	char s[100001];
	scanf("%s",s);
	map<char, int> char_freq;
	int i,max_freq=0;
	for(i=0;i<strlen(s);i++) {
		char_freq[s[i]]++;
		if(char_freq[s[i]]>max_freq) {
			max_freq=char_freq[s[i]];
		}
	}
	map<int,int> freq_freq;
	map<char, int>::iterator it;
	for(it=char_freq.begin();it!=char_freq.end();++it) {
		freq_freq[ it->second ]++;
	}
	/*
	if(freq_freq.size()>2) {
		printf("NO\n");
		return 0;
	}
	if(freq_freq[1]>1) {
		printf("NO\n");
		return 0;
	}
	if(freq_freq[1]==1) {
		printf("YES\n");
		return 0;
	}
	*/
	if((strlen(s)-(freq_freq[max_freq]*max_freq))<=1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}


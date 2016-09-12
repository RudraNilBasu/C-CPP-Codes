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
		char_freq[s[i]]++; // freq of occurance of each char
		if(char_freq[s[i]]>max_freq) {
			max_freq=char_freq[s[i]];
		}
	}
	map<int,int> freq_freq;
	map<char, int>::iterator it;
	for(it=char_freq.begin();it!=char_freq.end();++it) {
		freq_freq[ it->second ]++;
	}
	if(freq_freq.size()>2) {
		printf("NO\n");
		return 0;
	}
	if(freq_freq.size()==1) {
		printf("YES\n");
		return 0;
	}
	// calculate no of one and non ones
	int one=0,not_one=0;
	map<int,int>::iterator it_1;
	for(it_1=freq_freq.begin();it_1!=freq_freq.end();++it_1) {
		if(it_1->second==1) {
			one++;
		} else {
			not_one++;
		}
		//printf("freq of [%d] occurance=%d\n",it_1->first,it_1->second);
	}
	if(one==0) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	/*
	if((strlen(s)-(freq_freq[max_freq]*max_freq))<=1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	*/
	return 0;
}


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

#define ll long long int

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	//map<char, int> hash;
	//int hash[130];
	while(n--) {
		char inp[100001];
		scanf("%s",inp);
		//map<char, int> hash;
		//hash.clear();
		//memset(hash, 0, sizeof(hash));
		int hash[130]={0};
		int i,cost=0;
		for(i=0;i<strlen(inp);i++) {
			if(hash[inp[i]]==0) {
				cost++;
			}
			hash[inp[i]]++;
		}
		printf("%d\n",cost);
		//printf("%d\n",(int)hash.size());
	}
	return 0;
}


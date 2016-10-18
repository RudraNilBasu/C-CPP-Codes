#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

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
	int t,i,count;
	char s[1001];
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s);
		count=0;
		for(i=0;i<strlen(s);i++) {
			if(s[i]>='1' && s[i]<='9') {
				count+=s[i]-'0';
			}
		}
		printf("%d\n",count);
	}
	return 0;
}


#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	int t,zero,one,i;
	char s[100001];
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s);
		zero=0;
		one=0;
		for(i=0;i<strlen(s);i++) {
			if(s[i]=='0') {
				zero++;
			} else {
				one++;
			}
		}
		if(one==1 || zero==1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}

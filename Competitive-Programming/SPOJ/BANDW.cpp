#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	char given[501],reqd[501],help[501];
	int i,ans;
	while(1) {
		scanf("%s %s",given,reqd);
		if(given[0]=='*' && reqd[0]=='*')
			break;
		for(i=0;i<strlen(given);i++) {
			if(given[i]!=reqd[i]) {
				help[i]='X';
			} else {
				help[i]='O';
			}
		}
		ans=0;
		if(help[0]=='X') {
			ans++;
		}
		for(i=1;i<strlen(given);i++) {
			if( (help[i]=='X' && help[i-1]=='O')  ) {
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

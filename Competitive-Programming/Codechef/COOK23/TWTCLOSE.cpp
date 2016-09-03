#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	int n,k,i,ans,x;
	scanf("%d %d",&n,&k);
	bool isOpen[n+1];
	char inp[10];
	memset(isOpen, false, sizeof(isOpen));
	ans=0;
	for(i=0;i<k;i++) {
		scanf("%s",inp);
		if(inp[2]=='O') {
			memset(isOpen, false, sizeof(isOpen));
			ans=0;
		} else if(inp[2]=='I') {
			scanf("%d",&x);
			isOpen[x]=!isOpen[x];
			if(isOpen[x]) {
				ans++;
			} else {
				ans--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

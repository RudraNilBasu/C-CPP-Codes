#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	char s[1001];
	int i;
	while(scanf("%s",s)!=EOF) {
		int u=0,l=0;
		for(i=0;i<strlen(s);i++) {
			if(i%2) {
				if(s[i]<'a') {
					l++;
				} else {
					u++;
				}
			} else {
				if(s[i]>='a') {
					l++;
				} else {
					u++;
				}
			}
		}
		if(l<u) {
			printf("%d\n",l);
		} else {
			printf("%d\n",u);
		}
	}
}

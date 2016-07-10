#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	char s[10001];
	int k;
	k=1;
	while(scanf("%s",s)!=EOF) {
		int count=0,pos=-1,i;
		int find=1;
		for(i=0;i<strlen(s);i++) {
			if((s[i]-'0')==find) {
				count++;
				find=!find;
			}
		}
		printf("Game #%d: %d\n",(k++),count);
	}
	return 0;
}

#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	int t,i,len,flag;
	char s[12346];
	scanf("%d",&t);
	while(t--) {
		flag=0;
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<len;i++) {
			if(s[i]=='.') {
				if(len%2) {
					// if length is odd
					// if currently in the middle
					int mid=(len-1)/2;
					if(i==mid) {
						s[i]='a';
					} else {
						// if left side
						int other;
						if(i<mid) {
							// check other side is same or not
							other=(len-1)-i;
							if(s[other]!='.') {
								s[i]=s[other];
							} else {
								s[i]='a';
								s[other]='a';
							}
						}
						// if right side
						else if(i>mid) {
							// if corresponding left side was empty
							// it would have been covered
							other=(len-1)-i;
							if(s[other]!='.') {
								s[i]=s[other];
							} else {
								s[other]='a';
								s[i]='a';
							}
						}
					}
				} else {
					// if length is even
					int other=len-1-i;
					if(s[other]=='.') {
						s[i]='a';
						s[other]='a';
					} else {
						s[i]=s[other];
					}
				}
			} else {
				int other=(len-i-1);
				if(s[i]!='.' && s[other]!='.' && s[i]!=s[other]) {
					printf("-1\n");
					flag=1;
					break;
				}
			}
		}
		if(!flag) {
			printf("%s\n",s);
		}
	}
	return 0;
}

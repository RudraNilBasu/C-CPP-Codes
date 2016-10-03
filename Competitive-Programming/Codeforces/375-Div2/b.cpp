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

int findNext(char s[], int i, int len)
{
	while(i<len) {
		if(s[i]==')') {
			return i;
		}
		i++;
	}
}

bool isLetter(char a)
{
	if(a>='a' && a<='z')
		return true;
	if(a>='A' && a<='Z')
		return true;
	return false;
}

int findPare(char s[], int i, int len)
{
	while(i<len) {
		if(s[i]=='(')
			return i;
		i++;
	}
	return -1;
}

int findClose(char s[], int i, int len)
{
	while(i<len) {
		if(s[i]==')')
			return i;
		i++;
	}
	return -1;
}

int main()
{
	int len,i;
	scanf("%d",&len);
	char s[len+1];
	scanf("%s",s);
	bool hasStarted=false;
	// len of longest outside ()
	int maxWrd=0,cnt=0;
	for(i=0;i<len;i++) {
		if(s[i]=='_' && !hasStarted) {
			continue;
		}
		if(s[i]=='(' && !hasStarted) {
			i=findNext(s,i,len);
			continue;
		}
		if(isLetter(s[i]) && !hasStarted) {
			cnt=0;
			cnt++;
			hasStarted=true;
		} else if(isLetter(s[i]) && hasStarted) {
			cnt++;
		}

		if(s[i]=='_'&& hasStarted) {
			if(maxWrd<cnt) {
				maxWrd=cnt;
				cnt=0;
			}
			hasStarted=false;
		}
		if(s[i]=='(' && hasStarted) {
			if(maxWrd<cnt) {
				maxWrd=cnt;
				cnt=0;
			}
			hasStarted=false;
			i=findNext(s,i,len);
		}
	}
	if(hasStarted) {
		if(cnt>maxWrd) {
			maxWrd=cnt;
		}
	}
	// no of words inside ()
	int mWord=0;
	i=0;
	int j,op,cl;
	while(i<len && i!=-1) {
		op=findPare(s,i,len);
		if(op==-1) {
			break;
		}
		cl=findClose(s,op,len);
		bool isWrd=false;
		for(i=op+1;i<cl;i++) {
			// count words
			if(s[i]=='_') {
				isWrd=false;
				continue;
			}
			if(isLetter(s[i]) && !isWrd) {
				isWrd=true;
				mWord++;
			}
		}
	}
	printf("%d %d\n",maxWrd,mWord);
	return 0;
}


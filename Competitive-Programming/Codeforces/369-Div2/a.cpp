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
	int n,i;
	scanf("%d",&n);
	char str[n][6];
	for(i=0;i<n;i++) {
		scanf("%s",str[i]);
	}
	bool found=false;
	for(i=0;i<n;i++) {
		if(str[i][0]==str[i][1] && str[i][0]=='O') {
			found=true;
			str[i][0]=str[i][1]='+';
			break;
		}
		if(str[i][3]==str[i][4] && str[i][3]=='O') {
			found=true;
			str[i][3]=str[i][4]='+';
			break;
		}
		/*
		printf("%c %c\n",str[i][0],str[i][1]);
		if(str[i][0]==str[i][1]) {
			printf("hue %c\n",str[i][0]);
		}
		*/
	}
	if(found) {
		printf("YES\n");
		for(i=0;i<n;i++) {
			printf("%s\n",str[i]);
		}
	} else {
		printf("NO\n");
	}
	return 0;
}


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
	char str[n+1];
	scanf("%s",str);
	//int count=0;
	vector<int> ans;
	for(i=0;i<strlen(str);i++) {
		if(str[i]=='B') {
			//count++;
			int j;
			int _ans=0;
			for(j=i;j<strlen(str);j++) {
				if(str[j]=='W') {
					//i=j;
					break;
				}
				_ans++;
			}
			i=j;
			ans.push_back(_ans);
		}
	}
	printf("%d\n",(int)ans.size());
	for(i=0;i<ans.size();i++) {
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}


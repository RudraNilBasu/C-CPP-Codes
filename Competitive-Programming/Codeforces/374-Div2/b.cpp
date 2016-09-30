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
	int n,k;
	scanf("%d %d",&n,&k);
	int pass[n];
	int i;
	char s[101];
	for(i=0;i<n;i++) {
		scanf("%s",s);
		pass[i]=strlen(s);
	}
	int passLen;
	scanf("%s",s);
	passLen=strlen(s);
	sort(pass,pass+n);
	// no of numbers before passLen in pass
	// no of passLen's in pass
	int count=0;
	int j=-1;
	for(i=0;i<n;i++) {
		if(pass[i]>passLen) {
			break;
		}
		if(pass[i]==passLen) {
			j=i;
			break;
		}
		count++;
	}
	int count2=0;
	while(j!=-1 && j<n && pass[j]==passLen) {
		count2++;
		j++;
	}
	//printf("%d %d\n",count,count2);
	int ans=count+5*(count/k);
	printf("%d ",ans+1);
	ans+=count2+5*(count2/k);
	printf("%d\n",ans);
	return 0;
}

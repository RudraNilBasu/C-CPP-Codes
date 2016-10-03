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

int calc(int count, int k)
{
	if(count%k==0) {
		return 5*((count-1)/k);
	} else {
		return 5*(count/k);
	}
}

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
	int count=0; // no of passwords of len < len of real pass
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
	int count2=0; // no of pass of len = len of real pass
	/*
	while(j!=-1 && j<n && pass[j]==passLen) {
		count2++;
		j++;
	}
	*/
	for(i=0;i<n;i++) {
		if(pass[i]==passLen) {
			count2++;
		} else if(pass[i]>passLen) {
			break;
		}
	}
	//printf("%d %d\n",count,count2);
	//int ans1=(count)+5*((count+1)/k) + 1;
	int ans1=(count+1) + calc(count+1,k);
	printf("%d ",ans1);
	//int ans2=count + calc(count, k);
	int ans2=(count2+count)+calc(count+count2,k);
	printf("%d\n",ans2);
	return 0;
}

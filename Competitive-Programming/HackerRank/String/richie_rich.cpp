#include<stdio.h>
#include<string.h>
#include<algorithm>

#define ll long long int

bool isPalin(char str[], int loop, int n)
{
	int i;
	for(i=0;i<n;i++) {
		if(str[i]!=str[n-i-1]) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n,k,i,loop;
	scanf("%d %d",&n,&k);
	char inp[n+1];
	int changed[n];
	scanf("%s",inp);
	if(n%2) {
		// odd
		loop=(n/2)+1;
	} else {
		// even
		loop=n/2;
	}
	int m=0;
	memset(changed, 0, sizeof(changed));
	// 0 = not changed
	// 1 = changed
	for(i=0;i<loop;i++) {
		if(m>=k) {
			break;
		}
		if(inp[i]!=inp[n-i-1]) {
			if(inp[i]>inp[n-i-1]) {
				inp[n-i-1]=inp[i];
			} else {
				inp[i]=inp[n-i-1];
			}
			changed[i]=changed[n-i-1]=1;
			m++;
		}
	}
	if(!isPalin(inp,loop, n)) {
		printf("-1\n");
		return 0;
	}
	if(m>=k) {
		printf("%s\n",inp);
		return 0;
	}
	for(i=0;i<loop && m<k;i++) {
		if(inp[i]!='9' && inp[n-i-1]!='9') {
			if(changed[i]) {
				if((m+1)<=k) {
					m++;
					inp[i]=inp[n-i-1]='9';
				}
			} else {
				if((m+2)<=k) {
					m+=2;
					inp[i]=inp[n-i-1]='9';
				}
			}
		}
	}

	if(m==k-1 && n%2) {
		inp[n/2]='9';
	}
	printf("%s\n",inp);
	return 0;
}


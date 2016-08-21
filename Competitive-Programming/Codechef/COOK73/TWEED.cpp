#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	int t,n,i, player, flag;
	char name[4];
	scanf("%d",&t);
	while(t--) {
		scanf("%d %s",&n,name);
		int a[n];
		int c=0;
		for(i=0;i<n;i++) {
			scanf("%d",a+i);
			if(a[i]%2==0) {
				c++;
			}
		}
		if(name[1]=='e') {
			// Dee (even)
			player=1;
		} else {
			// Dum (odd)
			player = 0;
		}
		if(n==1 && c==1 && player) {
			printf("Dee\n");
		} else {
			printf("Dum\n");
		}
		/*
		while(1) {
			if(player) {
				// even
				player = 0;
				flag=0;
				for(i=0;i<n;i++) {
					if(a[i]%2==0) {
						a[i]=0;
						flag=1;
						break;
					}
				}
				if(flag==0) {
					for(i=0;i<n;i++) {
						if(a[i]>1) {
							a[i]=1;
							flag=1;
							break;
						}
					}
					if(!flag) {
						printf("Dum\n");
						break;
					}
				}
			} else {
				// odd
				flag=0;
				player=1;
				for(i=0;i<n;i++) {
					if(a[i]%2==0) {
						flag=1;
						a[i]--;
						break;
					}
				}
				if(!flag) {
					flag=0;
					for(i=0;i<n;i++) {
						if(a[i]%2) {
							a[i]=0;
							flag=1;
							break;
						}
					}
					if(!flag) {
						printf("Dee\n");
						break;
					}
				}
			}
		}
		*/
	}
	return 0;
}

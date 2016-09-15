#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	int t,i,n,max,winner,points,ci,pno;
	bool isTie;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		isTie=false;
		max=-1;
		winner=-1;
		pno=1;
		while(n--) {
			scanf("%d",&ci);
			points=ci;
			int arr[ci];
			int hash[7]={0};
			memset(hash,0,sizeof(hash));
			for(i=0;i<ci;i++) {
				scanf("%d",arr+i);
				hash[arr[i]]++;
			}
			while(1) {
				int x=0;
				for(i=1;i<=6;i++) {
					if(hash[i]>0) {
						x++;
					}
				}
				if(x==4) {
					points=points+1;
				} else if(x==5) {
					points+=2;
				} else if(x==6) {
					points+=4;
				} else {
					break;
				}
				for(i=1;i<=6;i++) {
					if(hash[i]!=0) {
						hash[i]--;
					}
				}
			}
			// max points calc
			if(points==max) {
				isTie=true;
			} else if(points>max) {
				isTie=false;
				max=points;
				winner=pno;
			}
			pno++;
		}
		if(isTie) {
			printf("tie\n");
		} else {
			if(winner==1) {
				printf("chef\n");
			} else {
				printf("%d\n",winner);
			}
		}
	}
	return 0;
}

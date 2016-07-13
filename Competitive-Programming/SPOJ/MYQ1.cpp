#include<stdio.h>
#define ll long long int
using namespace std;
int main()
{
	int t,row,pos;
	ll n;
	int colNo=5;
	char type;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		if(n==1) {
			printf("poor conductor\n");
			continue;
		}
		ll x,y;
		x=(n-1)%colNo;
		y=(n-1)/colNo;
		row=y;
		if(x==0)
			row--;
		row++;
		printf("%d ",row);
		if(x==1 || x==0 ) {
			printf("W ");
			type='W';
		} else if( row%2==1 && (x==2 || x==3)  ) {
			printf("A ");
			type='A';
		} else if( row%2==0 && (x==4 || x==3) ) {
			printf("A ");
			type='A';
		} else {
			printf("M ");
			type='M';
		}
		if(type=='A') {
			int rem=n%10;
			if(rem==3 || rem==0) {
				printf("L");
			} else if(rem==4 || rem==9) {
				printf("R");
			}
		} else if(type=='M') {
			printf("R");
		} else if(type=='W') {
			if(x==1 && (row%2==1)) {
				printf("L");
			} else if(x==0 && (row%2==1)) {
				printf("R");
			} else if(x==1 && (row%2==0)) {
				printf("R");
			} else if(x==0 && (row%2==0)) {
				printf("L");
			}
		}
		printf("\n");
	}
	return 0;
}

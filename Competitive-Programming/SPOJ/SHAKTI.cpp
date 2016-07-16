#include<stdio.h>
using namespace std;
int a[1000001];
void pre()
{
	a[1]=0; // sorry
	int i;
	for(i=2;i<=1000000;i++) {
		a[i]=!a[i-1];
	}
}
int main()
{
	pre();
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		if(a[n]) {
			printf("Thankyou Shaktiman\n");
		} else {
			printf("Sorry Shaktiman\n");
		}
	}
}

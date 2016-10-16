#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define ll long long int

#define REAL 1
#define FAKE 0

bool isPrime[100000001];

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

ll gcd(ll a, ll b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}

using namespace std;

bool fill()
{
	ll i,j;
	memset(isPrime,true,sizeof(isPrime));
	isPrime[1]=false;
	for(i=2;i<=100000000;i++) {
		if(isPrime[i]) {
			for(j=i+i;j<=100000000;j+=i) {
				isPrime[j]=false;
			}
		}
	}
}
bool check(int m,int n)
{
	/*
	if(m==1||n==1)
		return true;
	if(m%n==0)
		return false;
	if(n%m==0)
		return false;
	return true;
	*/
	ll i;
	for(i=2;i<=min(m,n);i++) {
		if(m%i==0&&n%i==0)
			return false;
	}
	return true;
}
int main()
{
	//fill();
	int t;
	ll n,i,count;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		/*
		count=0;
		for(i=n-2;i>=1;i--) {
			//if(gcd(i,i+1)==1 && gcd(i,i+2)==1 && gcd(i+1,i+2)==1) {
			//if(isPrime[i] && isPrime[i+1] && isPrime[i+2]) {
			//if(gcd(i,i+2)==1) {
			if(i%2) {
			//if(check(i,i+1)&&check(i,i+2)&&check(i+1,i+2) ) {
				//printf("%lld %lld %lld\n",i,i+1,i+2);
				count = (count%n + i%n)%n;
			}
		}
		*/
		/*
		ll num;
		if(n%2==0) {
			num=n/2;
		} else {
			num=(n/2)+1;
		}
		//count = (num)*((2+(num-1)*2)/2);
		count = (num%n*num%n)%n;
		//count=count%n;
		printf("%lld\n",count);
		*/
		ll num=(n-1)/2;
		count=num*num;
		count=count%n;
		printf("%lld\n",count);
	}
	return 0;
}


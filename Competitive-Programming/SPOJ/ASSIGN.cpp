#include<stdio.h>
#define ll long long int
#define ison(i,k) (((i) >> (k) ) & 1)
using namespace std;
int n;
int like[20][20];
ll dp[1<<20];
int input()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&like[i][j]);
		}
	}
}
int check() 
{
	ll nmax = (1<<n);
	// dp[i] = no of ways of arranging assignments to students from 1 to i
	ll i,j;
	int k;
	for(i=0;i<nmax;i++) {
		dp[i]=0;
	}
	dp[0]=1; // no of ways to arrange assignments to 0 students = 1
	for(i=1;i<nmax;i++) {
		dp[i]=0;
		// each value of i is a unique set of students. i=1 => 000001 => a combination with only the 1st student
		int noOfStudents=0; // no of students in the set i
		ll m=i;
		while(m) {
			noOfStudents += (m&1);
			m=m/2;
		}
		// f(n,s) = sum( f(n-1,s excluding e, where e is the assignment liked by n)  )
		for(k=0;k<n;k++) {
			if( like[noOfStudents-1][k] && ison(i,k) ) {
				dp[i] += dp[i& ~(1<<k)];
			}
		}
	}
	printf("%lld\n",dp[(1<<n)-1]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		input();
		check();
	}
	return 0;
}

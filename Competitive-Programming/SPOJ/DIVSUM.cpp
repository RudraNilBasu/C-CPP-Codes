#include<stdio.h>
#include<math.h>
#define ll long long int
using namespace std;
int calc_sum(int n)
{
    ll sum=0;
    int i;
    for(i=1;i<=sqrt(n);i++) {
        if(n%i==0) {
            sum+=i;
            if(i!=1 && i!=(sqrt(n)))
                sum+=(n/i);
        }
    }
    printf("%lld\n",sum);
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--) {
	    scanf("%d",&n);
	    if(n!=1)
	        calc_sum(n);
	    else
	        printf("0\n");
	}
	return 0;
}

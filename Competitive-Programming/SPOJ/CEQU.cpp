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


int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int t,count=0;
	scanf("%d",&t);
	while(t--) {
		count++;
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(c%gcd(abs(a),abs(b))==0) {	
			printf("Case %d: Yes\n",count);
		} else {
			printf("Case %d: No\n",count);
		}
	}
	return 0;
}


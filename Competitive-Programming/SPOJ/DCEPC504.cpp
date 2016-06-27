#include<stdio.h>
#include<math.h>
#define ll long long int
#define llu unsigned long long int
using namespace std;
char compliment(char ch)
{
		if(ch=='M')
			return 'F';
		return 'M';
}
char calc(int n, ll k)
{
	if(n==0 && k==0)
		return 'M';
	// finding the index of the parent node
	ll parent = k/2;
	// find the gender of the parent node
	char ch = calc(n-1,parent);
	// checking if it is the first child or not
	if(parent*2!=k)
		return compliment(ch);
	return ch;
}
int main()
{
	int t,n;
	ll k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %lld",&n,&k);
		//N = generation (int
		//K= index (ll))
		n--; // converting to 0 index
		k--;
		char ch=calc(n,k);
		if(ch=='M') {
			printf("Male\n");
		} else {
			printf("Female\n");
		}
	}
	return 0;
}


//http://abitofcs.blogspot.com/2014/10/spoj-gnyr09f-adjacent-bit-count.html
#include<stdio.h>
#include<string.h>
#define ll long long int
using namespace std;
int a[2][1002][1002];
int fillup()
{
	// pre-compute the array a[][][]
	// a[end bit][adj(s)][len(s)]
	int len,k;
	memset(a,0,sizeof(a));
	a[1][0][1]=1;
	a[0][0][1]=1;
	int doOnce=0;
	for(len=2;len<=1000;len++)
	{
		for(k=0;k<=len;k++)
		{
			a[0][k][len]=a[0][k][len-1]+a[1][k][len-1];
			a[1][k][len]=a[1][k-1][len-1]+a[0][k][len-1];
		}
	}
}
int main()
{
	fillup();
	int p,testNo,n,k;
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d %d %d",&testNo,&n,&k);
		// n = no of bits
		// k = adj bit count
		printf("%d %d\n",testNo,(a[0][k][n]+a[1][k][n]));
	}
	return 0;
}

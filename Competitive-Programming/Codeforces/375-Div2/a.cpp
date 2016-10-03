#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<limits.h>

#define ll long long int

int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}

using namespace std;

int mod(int a)
{
	if(a>=0)
		return a;
	return -1*a;
}

int find(int a, int b, int c)
{
	return (a+b+c)/3;
}

int findDistance(int a, int b, int c, int cg)
{
	return abs(a-cg)+abs(b-cg)+abs(c-cg);
}

int hue(int a, int b, int c)
{
	int i,dist=INT_MAX;
	for(i=1;i<=100;i++) {
		int _dist=findDistance(a,b,c,i);
		if(_dist<dist) {
			dist=_dist;
		}
	}
	printf("%d\n",dist);
}

int main()
{
	int a,b,c,cg;
	scanf("%d %d %d",&a,&b,&c);
	/*
	cg=find(a,b,c);
	int dist=0;
	dist=mod(a-cg)+mod(b-cg)+mod(c-cg);
	printf("%d\n",dist);
	*/
	hue(a,b,c);
	return 0;
}


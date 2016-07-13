#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct rect {
	int x;
	int y;
}rect;
int max(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}
int ab(int n)
{
	if(n>=0)
		return n;
	return -1*n;
}
int n;
int dp[1000][1000];
rect* rects;
int calc(int prev_ht, int index)
{
	if(index>=n)
		return 0;
	if(dp[prev_ht][index]!=-1)
		return dp[prev_ht][index];
	if(index==0) {
		return dp[prev_ht][index]=max(
				rects[index].x+calc(rects[index].y, index+1),
				rects[index].y+calc(rects[index].x, index+1)
				);
	}
	return dp[prev_ht][index]=max(
			ab(prev_ht - rects[index].x)+rects[index].y+calc(rects[index].x, index+1),
			ab(prev_ht - rects[index].y)+rects[index].x+calc(rects[index].y, index+1)
			);
}
int main()
{
	int i;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	rects = (rect *)malloc(n*sizeof(rect));
	for(i=0;i<n;i++) {
		scanf("%d %d",&rects[i].x, &rects[i].y);
	}
	printf("%d\n",calc(0,0));
	return 0;
}

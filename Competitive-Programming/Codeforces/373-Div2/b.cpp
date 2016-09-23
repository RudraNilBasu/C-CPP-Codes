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

int n;

int min3(int a, int b, int c)
{
	return min(a,min(b,c));
}

char invert(char col)
{
	if(col=='b')
		return 'r';
	return 'b';
}

int findMin(char str[], int index,int last)
{
	if(index>=n) {
		return 0;
	}
	if(last==str[index]) {
		int p=0,s=0;
		// either paint this one
		p=findMin(str, index+1, invert(str[index]));
		// or swap colors if possible
		int r=0;
		if(index!=(n-1) && str[index]!=str[index+1]) {
			//swap(s[index],s[index+1]);
			str[index]=(str[index+1]+str[index])-(str[index+1]=str[index]);
			r=findMin(str, index+1, str[index]);
			return 1+min(p,r);
		} else {
			return 1+p;
		}
	} else {
		return findMin(str, index+1, str[index]);
	}
}
int main()
{
	int i;
	char last;
	scanf("%d",&n);
	char s[100001];
	scanf("%s",s);
	// checking considering 1st one is 
	// in its correct pos
	int index=0;
	last=s[index];
	int cost=findMin(s,1,last);
	int cost1=0,cost2=0;
	// color first one
	cost1 = findMin(s,1,invert(last));
	// swap 1st 2
	s[0]=(s[1]+s[0])-(s[1]=s[0]);
	cost2=findMin(s,1,s[0]);
	cost=min3(cost, cost1, cost2);
	printf("%d\n",cost);
	return 0;
}


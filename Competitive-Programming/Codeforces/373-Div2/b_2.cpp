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

int main()
{
	int n;
	scanf("%d",&n);
	char s[n];
	scanf("%s",s);
	// checking brbrbrbrbrbr
	int i,x1,y1;
	int incx=0;
	char correct='b';
	//x=0;
	x1=y1=0;
	for(i=0;i<n;i++) {
		if(s[i]!=correct) {
			//x++;
			incx++;
		}
		// interchanging
		if(correct=='b') {
			correct='r';
		} else {
			correct='b';
		}
		if(i%2) {
			if(s[i]!='r') {
				y1++;
			}
		} else {
			if(s[i]!='b') {
				x1++;
			}
		}
	}
	// checking rbrbrbrbrbrb
	y=0;
	int incy=0;
	correct='r';
	for(i=0;i<n;i++) {
		if(s[i]!=correct) {
			//y++;
			incy++;
		}
		// interchanging
		if(correct=='b') {
			correct='r';
		} else {
			correct='b';
		}
		if(i%2) {
			if(s[i]!='b') {
				x1++;
			}
		} else {
			if(s[i]!='r') {
				y1++;
			}
		}
	}
	int calc=0;
	// min(x,y) is the amount exchanged
	if(incx>incy) {
		calc=min(x,y)
	} else {
		//
	}
	return 0;
}


#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int createArray(int Z[], string concat) {
	int i,left,right,n,k;
	left=0;
	right=0;
	n=concat.length();
	for(i=1;i<n;i++) {
		if(i>right) {
			// normal comparison
			left=right=i;
			while(right<n && concat[right]==concat[right-left]) {
				right++;
			}
			Z[i]=(right-left);
			right--;
		} else {
			if(Z[i-left]<(right-i+1)) {
				Z[i]=Z[i-left];
			} else {
				left=i;
				while(right<n && concat[right]==concat[right-left]) {
					right++;
				}
				Z[i]=(right-left);
				right--;
			}
		}
	}
}
int search(string text, string pattern)
{
	string concat=pattern+"$"+text;
	int len = concat.length();
	// creating the Z[] array
	int Z[len];
	createArray(Z,concat);
	// searching for the pattern
	int i=0;
	for(i=0;i<len;i++) {
		if(Z[i]==pattern.length()) {
			int pos = i-(pattern.length()+1);
			printf("The Pattern exists at position %d\n",pos);
		}
	}
}
int main()
{
	string text,pattern;
	cin>>text;
	cin>>pattern;
	search(text,pattern);
	return 0;
}

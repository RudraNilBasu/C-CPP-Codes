#include<stdio.h>
#include<string.h>
using namespace std;
char find(char a,char b)
{
	char i;
	for(i='A';i<='D';i++) {
		if(a!=i && b!=i) {
			return i;
		}
	}
}
char findNext(char a, char b, char c)
{
	char i='A';
	for(;i<='D';i++) {
		if( i!=a && i!=b && i!=c ) {
			return i;
		}
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	//printf("\n");
	char s1[2*n+1],s2[2*n+1];
	scanf("%s",s1);
	s2[0]=find(s1[0],s1[1]);
	s2[1]=findNext(s2[0],s1[0],s1[1]);
	printf("%c%c",s2[0],s2[1]);
	for(i=2;i<(2*n);i+=2) {
		s2[i]=findNext(s1[i],s1[i+1],s2[i-1]);
		s2[i+1]=findNext(s1[i],s1[i+1],s2[i]);
		printf("%c%c",s2[i],s2[i+1]);
	}
	printf("\n");
	return 0;
}

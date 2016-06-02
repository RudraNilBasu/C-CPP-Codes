#include<stdio.h>
#include<string.h>
using namespace std;
int size(int n)
{
	if(n<10)
		return 1;
	if(n<100)
		return 2;
	if(n<1000)
		return 3;
	if(n<10000)
		return 4;
	return -1;
}
int convert(int n)
{
	int len=size(n); // no of chars in the num (size)
	int m=0,c=0,x=0,i=0;
	if(len==1) {
		i=n%10;
	} else if(len==2) {
		i=n%10;
		x=(n%100-i)/10;
	} else if(len==3) {
		i=n%10;
		x=(n%100-i)/10;
		c=(n%1000-x-i)/100;
	} else if(len==4) {
		i=n%10;
		x=(n%100-i)/10;
		c=(n%1000-x-i)/100;
		m=(n%10000-c-x-i)/1000;
	}
	// printing
	if(m!=0) {
		if(m==1)
			printf("m");
		else
			printf("%dm",m);
	}
	if(c!=0) {
		if(c==1)
			printf("c");
		else
			printf("%dc",c);
	}
	if(x!=0) {
		if(x==1)
			printf("x");
		else 
			printf("%dx",x);
	}
	if(i!=0) {
		if(i==1)
			printf("i");
		else
			printf("%di",i);
	}
	printf("\n");
	return 0;
}
int num(char s[])
{
	int len=strlen(s);
	int i,n=1,sum=0;
	char ch;
	for(i=0;i<len;i++) {
		if(s[i]>'0' && s[i]<='9') {
			n=s[i]-'0';
		} else {
			ch=s[i];
			if(ch=='m')
				sum+=(1000*n);
			else if(ch=='c')
				sum+=(100*n);
			else if(ch=='x')
				sum+=(10*n);
			else if(ch=='i')
				sum+=n;
			n=1;
		}
	}
	return sum;
}
int main()
{
	int t;
	char s1[9],s2[9];
	scanf("%d",&t);
	while(t--) {
		scanf("%s %s",s1,s2);
		int sum=num(s1)+num(s2);
		convert(sum);
	}
	return 0;
}

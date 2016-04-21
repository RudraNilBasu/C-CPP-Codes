#include<stdio.h>
using namespace std;
int convert(int n)
{
	int val=0;
	while(n>0)
	{
		if(n&1)
		{
			// if last digit is 1
			val=(val*2)+1;
		}
		else
		{
			// if last digit is 0
			val=val*2;
		}
		n=n/2; //shifting right
	}
	return val;
}
int main()
{
	int n,a;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		if(a&1) printf("%d\n",a);
		else printf("%d\n",convert(a));
	}
	return 0;
}

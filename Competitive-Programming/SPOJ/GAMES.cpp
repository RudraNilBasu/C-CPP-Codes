#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
long int gcd(long int a, long int b)
{
	if(a==0) return b;
	return gcd(b%a,a);
}
int main()
{
	long int frac,i,flag,count,flage,number,t,num=0,deno=0,g,lft,rt,d1,d2;
	char s[20];
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",s);
		flag=0;
		num=0;
		deno=0;
		int k=0;
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]=='.') 
			{
				flag=1;
				continue;
			}
			num=num*10+(s[i]-48);
			if(flag)
			{
				k++;
			}
		}
		deno=pow(10,k);
		printf("%ld\n",deno/gcd(num,deno));
	}
	return 0;
}

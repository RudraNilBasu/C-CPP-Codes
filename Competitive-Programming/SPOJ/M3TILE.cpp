/*
   Link - https://www.quora.com/Can-somebody-explain-solution-to-SPOJ-com-Problem-M3TILE/answer/Meetu-Agarwal
 */
#include<stdio.h>
using namespace std;
int main()
{
	int x[31];
	int i,n;
	x[0]=1;
	x[1]=0;
	x[2]=3;
	x[3]=0;
	for(i=4;i<=30;i++)
	{
		x[i]=4*x[i-2]-x[i-4];
	}
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) break;
		printf("%d\n",x[n]);
	}
}

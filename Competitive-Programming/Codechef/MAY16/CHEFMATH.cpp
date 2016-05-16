#include<stdio.h>
#define ll long long int
#define SIZE 10000
using namespace std;
ll f[SIZE+2];
int main()
{
	f[0]=1;
	f[1]=2;
	int i;
	for(i=2;i<=SIZE+1;i++)
		f[i]=f[i-1]+f[i-2];
	return 0;
}

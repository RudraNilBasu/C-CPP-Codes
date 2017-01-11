#include<stdio.h>

int fibo(int n, int a, int b)
{
	if(n<=1)
		return a;
	return fibo(n-1, a+b, a);
}

int main()
{
	printf("%d\n",fibo(5,0,1));
	return 0;
}

//http://www.spoj.com/problems/FIBOSUM/
/*
Ans = fib(m+2)-fib(n+2)-2
Related stuff - http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

Logic for calculating the nth Fibonacci number-
Let F[][]={{1,1},{1,0}}
Now, F=F^n
F[0][0] will contain the value of n+1th fibonacci number

Negative mod stuff-
if abs(b)>abs(a)
then a%b is #define MODULO(a,b) ((a>=0)?(a%b):((b+a)%b))
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define ll unsigned long long int
#define PHI (0.5*(1+sqrt(5)))
#define MOD 1000000007
using namespace std;
void multiply(ll a[2][2] , ll b[2][2])
{
    ll res[2][2];
    memset(res , 0 , sizeof res);
    for(int i = 0 ; i < 2 ; i ++)
        for(int j = 0 ; j < 2 ; j++)
            for(int k = 0 ; k < 2 ; k++)
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            a[i][j] = res[i][j];
}
int power(ll F[2][2], ll n)
{
  if( n == 0 || n == 1)
      return 0;
  ll M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}
ll fib(ll n)
{
    ll F[2][2]={{1,1},{1,0}};
    if(n==0)
    {
        return 0;
    }
    // finding F ^ n-1
    power(F,n-1);
    return F[0][0];
}
int main()
{
    int t;
    ll n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu %llu",&n,&m);
        printf("%llu\n",(fib(m+2)-fib(n+1) +MOD)%MOD);
    }
    return 0;
}

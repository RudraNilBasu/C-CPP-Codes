//http://www.spoj.com/problems/DANGER/
/*
Discussion - http://www.exploringbinary.com/powers-of-two-in-the-josephus-problem/
*/
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    char inp[4];
    int n;
    while(1)
    {
        n=0;
        // input in the given format
        scanf("%s",inp);
        int x=inp[0]-48;
        int y=inp[1]-48;
        int z=inp[3]-48;
        if(x==0 && y==0 && z==0) break;
        // converting input format to number format
        n=n*10+x;
        n=n*10+y;
        while(z--)
        {
            n*=10;
        }
        // if n is a power of 2, answer is 1
        int m=n&(n-1);
        if(m==0)
        {
            printf("1\n");
        }
        else
        {
            // n=2^m+k. Ans = 2*k+1
            m=(int)log2(n);
            int k = n-(1<<m);
            printf("%d\n",(2*k+1));
        }
    }
}

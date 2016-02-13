// Program to reset the leftmost set bit
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int n = 1578;
    int m = (int)log2(n);  // the leftmost set bit location
    int x = (1<<m);   // the number 2^m
    int res = n-x;      // the number with leftmost bit reset
    printf("%d\n",res);
    return 0;
}

#include<stdio.h>
#include<cstring>
using namespace std;
int MAX(int a, int b)
{
    if(a>b)
    return a;
    return b;
}
int lps(char seq[], int i, int j)
{
    if(i==j) return 1;
    if(seq[i]!=seq[j])
    {
        return MAX(
                   lps(seq,i,j-1),
                   lps(seq,i+1,j)
                   );
    }
    if(i+1==j)
    {
        return 2;
    }
    else
    {
        return lps(seq,i+1,j-1)+2;
    }
}
int main()
{
    char seq[]="BBABCBCAB";
    int n=strlen(seq);
    printf("LPS of the given string is %d\n",lps(seq,0,n-1));
}

//http://www.spoj.com/problems/DIEHARD/
#include<stdio.h>
#define FIRE 0
#define WATER 1
#define AIR 2
using namespace std;
int dp[1004][1004][3]; // dp[] returns the max time for a given value of H and A and element
int max2(int a, int b)
{
    if(a>=b)
    return a;
    return b;
}
int max3(int a, int b, int c)
{
    if(a>max2(b,c))
    return a;

    if(b>max2(a,c))
    return b;

    return c;
}
int find(int element, int h, int a)
{
    // decreasing health and armour based on where the player is
    if(element==AIR)
    {
        h+=3;
        a+=2;
    }
    else if(element==FIRE)
    {
        h-=20;
        a+=5;
    }
    else if(element==WATER)
    {
        h-=5;
        a-=10;
    }

    if(h<=0 || a<=0)
    return 0;

    if(dp[h][a][element]!=-1)
    return dp[h][a][element];


    if(element==WATER)
    {
        return dp[h][a][element]=1+max2(find(AIR,h,a),find(FIRE,h,a));
    }

    else if(element==AIR)
    {
        return dp[h][a][element]=1+max2(find(WATER,h,a),find(FIRE,h,a));
    }

    else if(element==FIRE)
    {
        return dp[h][a][element]=1+max2(find(AIR,h,a),find(WATER,h,a));
    }
}
int refresh()
{
    int i,j,k;
    for(i=0;i<1004;i++)
    {
        for(j=0;j<1004;j++)
        {
            for(k=0;k<3;k++)
            dp[i][j][k]=-1;
        }
    }
}
int main()
{
    int t,res,h,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&h,&a);
        refresh();
        res=max3(find(FIRE,h,a),find(WATER,h,a),find(AIR,h,a));
        printf("%d\n",res);
    }
    return 0;
}

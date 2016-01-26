//http://www.spoj.com/problems/QUADAREA/
#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    double a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        double s=(a+b+c+d)/2;
        printf("%.2f\n",sqrt((s-a)*(s-b)*(s-c)*(s-d)));
    }
}

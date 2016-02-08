//http://www.spoj.com/problems/PIR/
/*
Formula V = abc/6 * sqrt( 1 + 2*cos a cos b cos c - cos2 a - cos2 b - cos2 c )
*/
#include<stdio.h>
#include<math.h>
using namespace std;
double cosine(int a, int b, int c)
{
    double temp=(a*a+b*b-c*c)/(2.0*a*b);
    return temp;
}
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        int  AB, AC, AD, BC, BD, CD;
        scanf("%d%d%d%d%d%d", &AB, &AC, &AD, &BC, &BD, &CD);
        double cos1,cos2,cos3;
        double ans;
        cos1 = cosine(AD, BD, AB);
		cos2 = cosine(BD, CD, BC);
		cos3 = cosine(CD, AD, AC);
		ans=sqrt(1+(2*cos1*cos2*cos3)-(cos1*cos1)-(cos2*cos2)-(cos3*cos3));
		ans=((AD*BD*CD)*ans)/6;
		printf("%0.4lf\n",ans);
    }
    return 0;
}

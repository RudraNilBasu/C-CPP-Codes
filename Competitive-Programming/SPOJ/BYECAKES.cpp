//http://www.spoj.com/problems/BYECAKES/
#include<stdio.h>
using namespace std;
int main()
{
    int e1,f1,s1,m1,e2,f2,s2,m2;
    scanf("%d %d %d %d %d %d %d %d",&e1,&f1,&s1,&m1,&e2,&f2,&s2,&m2);
    while(e1!=-1 &&f1!=-1 && s1!=-1 && m1!=-1)
    {
        while(e1>0 || f1>0 || s1>0 || m1>0)
        {
            e1-=e2;
            f1-=f2;
            s1-=s2;
            m1-=m2;
        }
        printf("%d %d %d %d\n",(e1*-1),(f1*-1),(s1*-1),(m1*-1));
        scanf("%d %d %d %d %d %d %d %d",&e1,&f1,&s1,&m1,&e2,&f2,&s2,&m2);
    }
    return 0;
}

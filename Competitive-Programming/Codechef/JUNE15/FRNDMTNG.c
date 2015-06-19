//http://www.codechef.com/JUNE15/problems/FRNDMTNG

#include<stdio.h>
int square(long long T,long long t1,long long t2)
{
    double a1=0,a2=0,ans=0;
    a1=0.5*(T-t1)*(T-t1);
    a2=0.5*(T-t2)*(T-t2);
    //printf("a1=%f\na2=%f\n",a1,a2);
    if(t2>=T)
    {
        a2=0;
    }
    if(t1>=T)
    {
        a1=0;
    }
    ans=(T*T)-(a1+a2);
    ans=ans/(T*T);
    printf("%f\n",ans);
    return 0;
}
int main()
{
    long long T,A,B,t1,t2;
    double a1=0,a2=0,ans=0;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld %lld %lld",&A,&B,&t1,&t2);
        if(A==B)
        {
            square(A,t1,t2);
        }
        else if(A>B)  //if T1>T2. Then T2 OR B will be in the X Axis
        {
 
            if((B+t2)<A)
            {
                a1=0.5*((A-(B+t2))+(A-t2))*B;
            }
            else
            {
                a1=0.5*(A-t2)*(A-t2);
            }
            a2=0.5*(B-t1)*(B-t1);
 
            if(t1>B)
            {
                a2=0;
            }
            if(t2>A)
            {
                a1=0;
            }
            ans=(A*B)-(a1+a2);
            ans=ans/(A*B);
            printf("%f\n",ans);
        }
        else if(B>A)
        {
            a2=0.5*(A-t2)*(A-t2);
 
            if((A+t1)<B)
            {
                a1=0.5*((B-(A+t1))+(B-t1))*A;
            }
            else
            {
                a1=0.5*(B-t1)*(B-t1);
            }
            if(t2>=A)
            {
                a2=0;
            }
            if(t1>=B)
            {
                a1=0;
            }
            ans=(A*B)-(a1+a2);
            ans=ans/(A*B);
            printf("%f\n",ans);
        }
    }
    return 0;
}

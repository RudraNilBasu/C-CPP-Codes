/*
http://www.spoj.com/problems/ANARC09A/
*/
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char inp[2001];
    int i,ans,t=0,count=0,top;
    while(1)
    {
        t++;

        scanf("%s",inp);


        count=0;
        top=0;
        i=0;

        if(inp[i]=='-')
        break;

        while(inp[i]!='\0')
        {
            if(inp[i]=='{')
            {
                ++top;
            }
            else if(inp[i]=='}')
            {
                if(top==0)
                {
                    ++top;
                    count++;
                }
                else
                {
                    top--;
                }
            }
            i++;
        }

        printf("%d. %d\n",t,(count+top/2));
    }
    return 0;
}

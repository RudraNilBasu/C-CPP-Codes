//http://www.spoj.com/problems/MFLAR10/
#include<stdio.h>
#include<string.h>
int convert(char s)
{
    if(s>='a' && s<='z')
    {
        return s-32;
    }
    return s+32;
}
int main()
{
    char s[1001];
    while(1)
    {
        gets(s);
        int len=strlen(s);
        if(len==0)
        {
            continue;
        }
        if(len==1 && s[0]=='*')
        {
            break;
        }
        char s1=s[0]; // the first letter of the first word
        int k=1,flag=0;
        while(s1==' ')
        {
            s1=s[k++]; // if the 1st word is preceeded by space, ignore it
        }
        char s2=convert(s1); // the other case (if s1 is upper case, s2 is lower and vice versa
        for(;k<len-1;k++)
        {
            //if(s[k]==' ' && (s[k+1]!=s1 || s[k+1]!=s2) )
            if(s[k]==' ')
            {
                if(s[k+1]!=s1 && s[k+1]!=s2)
                {
                    flag=1;
                    printf("N\n");
                    break;
                }
            }
        }
        if(!flag)
        {
            printf("Y\n");
        }
    }
    return 0;
}

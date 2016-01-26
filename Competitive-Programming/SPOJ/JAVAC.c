//http://www.spoj.com/problems/JAVAC/
#include<stdio.h>
#include<string.h>
int isLowerCase(char c)
{
    if(c>=97 && c<=122)
        return 1;
    return 0;
}
int isUpperCase(char c)
{
    if(c>=65 && c<=90)
        return 1;
    return 0;
}
int main()
{
    char inp[102]; // input string
    char out[202]; // output string
    int i,k=0,error=0;
    while(scanf("%s",inp)!=EOF)
    {
        k=0;
        error=0;
        int isJava=0; // to check if the input is java or c++
                      // = 1 for java. =2 for c++ .=0 means it is not yet decided
        // JAVA = the first word is written starting from the small letter,
        //and the following ones are written starting from the capital letter, no separators are used.
        // Rest all small letters

        //C++ people use only small letters in their identifiers. To separate words they use underscore character ‘_’.

        if(isLowerCase(inp[0])==0)
        {
            // 1st letter must be lower case for both
            // if not then throw error
            error=1;
            printf("Error!\n");
            continue;
        }

        // if last character is _
        if(inp[strlen(inp)-1]=='_')
        {
            error=1;
            printf("Error!\n");
            continue;
        }

        out[k++]=inp[0];

        for(i=1;i<strlen(inp);i++)
        {
            //printf("%c\n",inp[i]);
            if(isLowerCase(inp[i])==1)
            {
                out[k++]=inp[i];
            }
            else if(inp[i]>='1' &&inp[i]<='9')
            {
                out[k++]=inp[i];
            }
            //else if(isLowerCase(inp[i])==0 && inp[i]!='_')
            else if(isUpperCase(inp[i])==1)
            {
                //printf("isJava=%d\n",isJava);
                // if next character is upper case and isJava=0. Then it is C++
                if(isJava==0)
                {
                    isJava=1; // marking input as java
                    out[k++]='_';
                    out[k++]=inp[i]+32; // storing the small case equivalent
                }
                else if(isJava==2)
                {
                    error=1;
                    printf("Error!\n");
                    break;
                }
                else if(isJava==1)
                {
                    out[k++]='_';
                    out[k++]=inp[i]+32;
                }
            }
            else if(inp[i]=='_')
            {
                // if next character is '_'
                if(isJava==1)
                {
                    error=1;
                    printf("Error!\n");
                    break;
                }
                isJava=2; // it is c++
                i++;
                //printf("next is %c\n",inp[i]);
                if(isLowerCase(inp[i])==0)
                {
                    error=1;
                    printf("Error!\n");
                    break;
                }
                else
                {
                    out[k++]=inp[i]-32;
                }
            }
            else
            {
                error=1;
                printf("Error!\n");
                break;
            }
        }
        out[k++]='\0';
        if(error==0)
        {
            printf("%s\n",out);
        }
    }
    return 0;
}

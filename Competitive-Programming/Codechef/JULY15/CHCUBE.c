//https://www.codechef.com/JULY15/problems/CHCUBE/
//https://www.codechef.com/problems/CHCUBE

#include<stdio.h>
#include<string.h>
 
int main()
{
    int t,c;
    
    char front[10];
    char back[10];
    char top[10];
    char bottom[10];
    char left[10];
    char right[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",front);
        scanf("%s",back);
        scanf("%s",left);
        scanf("%s",right);
        scanf("%s",top);
        scanf("%s",bottom);
        if( strcmp(front,top)==0 && strcmp(front,left) ==0)
        {
            printf("YES\n");
            continue;
        }
        if( strcmp(front,top)==0 && strcmp(front,right) ==0)
        {
            printf("YES\n");
            continue;
        }
        if( strcmp(front,bottom)==0 && strcmp(front,left) ==0)
        {
            printf("YES\n");
            continue;
        }
        if( strcmp(front,bottom)==0 && strcmp(front,right) ==0)
        {
            printf("YES\n");
            continue;
        }
        if( strcmp(back,top)==0 && strcmp(back,left) ==0)
        {
            printf("YES\n");
            continue;
        }
        if( strcmp(back,top)==0 && strcmp(back,right) ==0)
        {
            printf("YES\n");
            continue;
        }
        if( strcmp(back,bottom)==0 && strcmp(back,left) ==0)
        {
            printf("YES\n");
            continue;
        }
        if( strcmp(back,bottom)==0 && strcmp(back,right) ==0)
        {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}

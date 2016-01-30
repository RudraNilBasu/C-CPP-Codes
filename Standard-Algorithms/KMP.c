/*
Program to implement KMP Search in a string
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int search(char txt[], char pat[])
{
    int M = strlen(pat); // length of the pattern
    int N = strlen(txt); // length of the text
    int *lps= (int *)malloc(M*sizeof(int));
    createLPS(lps,M,pat);
    int i=0; // marking the position for the txt[] array
    int k=0; // marking the position for the pat[] array
    while(i<N)
    {
        if(pat[k]==txt[i])
        {
            i++;
            k++;
        }
        if(k==M)
        {
            printf("Found a Match at position %d\n",(i-k));
        }
        else if((i<N && (pat[k]!=txt[i])))
        {
            // if they are not equal
            if(k!=0) // we are not ar the First position of the pat[] array
            {
                k=lps[k-1];
            }
            else
            {
                // if we are in the initial position of the pat[] array
                i++;
            }
        }
    }
}
int createLPS(int lps[], int M, int *pat)
{
    int i,j;lps[0]=0;
    i=1;
    j=0;
    while(i<M)
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else
        {
            if(j==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                j=lps[j-1];
            }
        }
    }
}
int main()
{
    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    search(txt,pat);
    return 0;
}

//http://www.spoj.com/problems/EGYPIZZA/
#include<stdio.h>
#include<string.h>
#include<string>
#include <stdlib.h>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(float*)b - *(float*)a );
}
int floatcomp(const void* elem1, const void* elem2)
{
    if(*(const float*)elem1 < *(const float*)elem2)
        return -1;
    return *(const float*)elem1 > *(const float*)elem2;
}
int main()
{
    int n,pizza,remhalf,remoneq,rem3q,i;
    char inp[4];
    char half[4]="1/2";
    char oneq[4]="1/4";
    char threeq[4]="3/4";
    char full[4]="1";

    scanf("%d",&n);

    pizza = 1; // no of pizza's = 1 at first bcoz 1 full pizza is already taken
    remhalf=0; // no of 1/2 pieces of pizza already present
    remoneq=0; // no of 1/4 pieces of pizza already present
    rem3q=0;   // no of 3/4 pieces of pizza left

    float *a=(float *)malloc(n*sizeof(float));
    for(i=0;i<n;i++)
    {
        scanf("%s",inp);
        if(strcmp(inp,half)==0)
        {
            a[i]=0.5;
        }
        else if(strcmp(inp,oneq)==0)
        {
            a[i]=0.25;
        }
        else if(strcmp(inp,threeq)==0)
        {
            a[i]=0.75;
        }
        else
        {
            a[i]=1.0;
        }
    }
    qsort(a,n,sizeof(float),floatcomp); // sorted in ascending order. Start checking from last
    for(i=n-1;i>=0;i--)
    {
        // checking the value of a[i]
        if(a[i]==1.0)
        {
            strcpy(inp, full);
        }
        else if(a[i]==0.25)
        {
            strcpy(inp,oneq);
        }
        else if(a[i]==0.5)
        {
            strcpy(inp,half);
        }
        else if(a[i]==0.75)
        {
            strcpy(inp,threeq);
        }


        if(strcmp(inp,half)==0)
        {
            // input is 1/2
            // check if 1/2 slice is already present or not
            if(remhalf>0)
            {
                remhalf--;
            }
            else if(rem3q>0)
            {
                //if a 3/4 is present, then extrsct 1/2 from 3/4
                rem3q--;
                //add the remaining 1/4 to leftover
                remoneq++;
            }
            else
            {
                //  slice is not present in leftover, buy new one
                pizza++;
                // keep the leftover
                remhalf++;
            }
        }
        else if(strcmp(inp,oneq)==0)
        {
            // input is 1/4
            // check if 1/4 slice is available or not
            if(remoneq>0)
            {
                remoneq--;
            }
            else if(rem3q>0)
            {
                rem3q--;
                remhalf++;
            }
            else if(remhalf>0)
            {
                // if a half is already present, make 1/4 out of it
                remhalf--;
                // keep the remaining 1/4 in leftover
                remoneq++;
            }
            else
            {
                // buy new full pizza
                pizza++;
                //keep the leftover
                rem3q++;
            }
        }
        else if(strcmp(inp,threeq)==0)
        {
            // input is 3/4
            // check if it is present or not in leftover
            if(rem3q>0)
            {
                // use the leftover
                rem3q--;
            }
            else
            {
                // no leftover, buy new one
                pizza++;
                // keep leftover
                remoneq++;
            }
        }
        else if(strcmp(inp,full)==0)
        {
            pizza++;
        }
    }
    printf("%d\n",pizza);
    return 0;
}

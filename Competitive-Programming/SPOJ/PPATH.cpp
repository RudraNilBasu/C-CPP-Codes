//http://www.spoj.com/problems/PPATH/

#include<bits/stdc++.h>
using namespace std;
bool check[10009];
void seive()  // performing seive to generate all 4 digit Prime numbers 
{
    int i,j;
    for(i=2;i<=100;i++)
    {
        if(!check[i])
        {
            for(j=i*i;j<=10000;j+=i)
            {
                check[j]=true;
            }
        }
    }
}

void arr(int a[],int num)    // storing the number "num" in an array a[] of size 4
{
    int w=3;
    while(num)
    {
        a[w--]=num%10;
        num/=10;
    }
}

int conv_num(int a[])    // returning the array a[] coverted to integer
{
    int temp=0,k=0;
    while(k<4)
    {
        temp=temp*10+a[k];
        k++;
    }
    return temp;
}

int main()
{
    int t;
    scanf("%d",&t);
    seive();
    while(t--)
    {
        int a,b,parent[10009],dist[10009],digit[4];   // parent[i] will store the parent of node [i]
        //dist[i] will store the shortest distance of node i from "a"
        scanf("%d %d",&a,&b);
        queue<int> q;
        memset(dist,-1,sizeof(dist));
        memset(parent,-1,sizeof(parent));
        dist[a]=0;
        parent[a]=0;
        q.push(a);
        while(!q.empty())
        {
            int num=q.front();
            for(int k=3;k>=0;k--)
            {
                arr(digit,num);    
                for(int i=0;i<=9;i++)
                {
                    digit[k]=i;    // taking all possible 4 digit numbers
                    int temp=conv_num(digit);
                    if((!check[temp]) && dist[temp]==-1 && temp>=1000)   // if the 4 digit generated number is i) prime ii) unvisited, and iii) have 4 digits
                    {
                        dist[temp]=dist[num]+1;
                        parent[temp]=num;
                        q.push(temp);
                    }
                }
            }
            q.pop();
        }
        if(dist[b]==-1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n",dist[b]);
        }
    }
    return 0;
}

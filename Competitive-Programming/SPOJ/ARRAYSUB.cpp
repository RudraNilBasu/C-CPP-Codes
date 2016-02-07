//http://www.spoj.com/problems/ARRAYSUB/
#include<stdio.h>
#include<deque>
using namespace std;
int n;
int a[1000000];
int k;
int printKMax()
{
    deque<int> Qi(k);
    // insert 1st k elements in the queue
    int i;
    for(i=0;i<k;i++)
    {
        while(!Qi.empty() && a[i]>a[Qi.back()])
        {
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    // working on the next a[k] to a[n-1] elements
    for(;i<n;i++)
    {
        // print the highest from the previous window
        printf("%d ",a[Qi.front()]);
        // remove elements from the last window
        while(!Qi.empty() && Qi.front()<=(i-k))
        {
            Qi.pop_front();
        }
        // Remove all elements smaller than the current element
        while(!Qi.empty() && a[i]>a[Qi.back()])
        {
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    // print the maximum of the last window
    printf("%d\n",a[Qi.front()]);
}
int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    printKMax();
    return 0;
}

/*
Implementation of Sliding Window algorithm using dequeue
*/
#include<stdio.h>
#include<deque>
using namespace std;
int printKMax(int a[], int n, int k)
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
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}

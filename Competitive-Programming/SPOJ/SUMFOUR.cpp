#include<stdio.h>
#include<algorithm>
#define MAX 10000001
using namespace std;
int ab[MAX];
int cd[MAX];
int binarysearch(int val,int k)
{
    int high=k,low=0,size=0,mid=0,temp=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(cd[mid]==val)
        {
            temp=mid-1;
            while(mid<k && cd[mid]==val)
            {
                size++;
                mid++;
            }
            while(temp>=0 && cd[temp]==val)
            {
                size++;
                temp--;
            }
            return size;
        }
        else if(val>cd[mid])
        {
            low=mid+1;
        }
        else if(val<cd[mid])
        {
            high=mid-1;
        }
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
	int a[4000],b[4000],c[4000],d[4000];
	int i,j,p=0,k=0;
	for(i=0;i<n;i++)
	{
	    scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
	        ab[p++]=a[i]+b[j];
	        cd[k++]=(c[i]+d[j])*-1;
	    }
	}
	sort(ab,ab+p);
	sort(cd,cd+k);
	int temp,size1=0,size2=0,count=0;
	for(i=0;i<p;)
	{
	    temp=ab[i];
	    // checking how many occurance of the same number exists in ab
	    size1=0;
	    while(i<p && temp==ab[i])
	    {
	        size1++;
	        i++;
	    }
	    // binary searching to check the number of occurance of the same number in cd
	    size2=binarysearch(temp,k);
	    count+=(size1*size2);
	}
	printf("%d\n",count);
    return 0;
}

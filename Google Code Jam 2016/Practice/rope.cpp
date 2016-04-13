// Rope Intranet
#include <iostream>
#include<stdio.h>

using namespace std;

int main() {
	int i,t,k,j,n,count;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
	    scanf("%d",&n);
	    int a[n],b[n];
	    count=0;
	    for(j=0;j<n;j++)
	    {
	        scanf("%d %d",&a[j],&b[j]);
	    }
	    for(j=0;j<n;j++)
	    {
	        for(k=j+1;k<n;k++)
	        {
	            if(a[k]>a[j] && b[k]<b[j])
	            {
	                count++;
	            }
	            else if(a[k]<a[j] && b[k]>b[j])
	            {
	                count++;
	            }
	        }
	    }
	    printf("Case #%d: %d\n",i,count);
	}
	return 0;
}

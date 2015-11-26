#include<stdio.h>
#define SIZE 5
int main()
{
	int a[5]={5,9,4,3,1}; // unsorted array
	int i,j,pos=0;
	for(i=0;i<SIZE;i++)
	{
		pos=i;
		for(j=i+1;j<SIZE ;j++)
		{
			if(a[pos]>a[j])
			{
				pos=j;
			}
		}
		if(pos!=i)
		{
			//swap a[pos] and a[i]
			int temp=a[pos];
			a[pos]=a[i];
			a[i]=temp;
		}
	}
	for(i=0;i<SIZE;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}

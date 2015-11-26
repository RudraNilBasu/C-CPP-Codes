#include<stdio.h>
int main()
{
	int a[5]={5,8,1,2,3}; // the array
	int i,j;
	for(i=1;i<4;i++)
	{
		j=i;
		while(j>0 && a[j-1]>a[j])
		{
			a[j-1]=a[j-1]+a[j];
			a[j]=a[j-1]-a[j];
			a[j-1]=a[j-1]-a[j];

			j--;
		}
	}
	for(i=0;i<4;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}

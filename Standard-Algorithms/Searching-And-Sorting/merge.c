#include<stdio.h>

int merge(int a[],int l,int m,int r)
{
	//int m=(l+r)/2;
	int n1,n2;
	n1=m-l+1;
	n2=r-m;

	int *L;
	int *R;
	L=(int *)malloc(n1*sizeof(int));
	R=(int *)malloc(n2*sizeof(int));

	int i,j;
	for(i=0;i<n1;i++)
	{
		L[i]=a[l+i];
	}
	for(i=0;i<n2;i++)
	{
		R[i]=a[m+1+i];
	}
	i=0,j=0;
	int k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i++];
		}
		else
		{
			a[k]=R[j++];
		}
		k++;
	}
	//remaining part
	while(i<n1)
	{
		a[k]=L[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		k++;
		j++;
	}
	return 0;
}

int mergeSort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
	return 0;
}
int main()
{
	int a[5]={5,9,4,1,3};
	mergeSort(a,0,4);
	printf("Array : \n");
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}

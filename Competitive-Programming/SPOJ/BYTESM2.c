/*
http://www.spoj.com/problems/BYTESM2/
Dynamic Programming
Starting from the second last row, for each element a[i][j] check which one is bigger among bottom element and the two diagonal elements.
Add the bigger one to the element a[i][j]
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,h,w,m,i,j,s=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&h,&w);
		int **a=(int **)malloc(h*sizeof(int *));
		for(i=0;i<h;i++)
		{
			a[i]=(int *)malloc(w*sizeof(int));
		}
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=h-2;i>=0;i--)
		{
			if(a[i+1][0]>a[i+1][1])
			{
				s=a[i+1][0];
			}
			else
			{
				s=a[i+1][1];
			}
			a[i][0]+=s;
			for(j=1;j<w-1;j++)
			{
				if(a[i+1][j-1]>=a[i+1][j] && a[i+1][j-1]>=a[i+1][j+1])
				{
					s=a[i+1][j-1];
				}
				else if(a[i+1][j]>=a[i+1][j-1] && a[i+1][j]>=a[i+1][j+1])
				{
					s=a[i+1][j];
				}
				else if(a[i+1][j+1]>=a[i+1][j-1] && a[i+1][j+1]>=a[i+1][j])
				{
					s=a[i+1][j+1];
				}
				a[i][j]+=s;
			}
			if(a[i+1][w-1]>=a[i+1][w-2])
			{
				s=a[i+1][w-1];
			}
			else
			{
				s=a[i+1][w-2];
			}
			a[i][w-1]+=s;
		}
		s=a[0][0];
		for(i=0;i<w;i++)
		{
			if(s<a[0][i])
			{
				s=a[0][i];
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
